//
// Created by Андрей on 13.04.2017.
//

#include "composite_shape.hpp"
#include <cmath>
#include <stdexcept>

CompositeShape::CompositeShape(std::shared_ptr<Shape> shape) :
  length_(0),
  shapes_(new std::shared_ptr<Shape>[1])
{
  if (!shape) {
    throw std::invalid_argument("Object not exist");
  }
  shapes_[length_++] = shape;
}
CompositeShape::CompositeShape(const CompositeShape &obj)
{
  if (this != &obj) {
    length_ = 0;
    array_type copyShape(new std::shared_ptr<Shape>[obj.getLength()]);
    for (int i = 0; i < obj.getLength(); ++i) {
      copyShape[i] = obj[i];
    }
    shapes_.swap(copyShape);
    length_ = obj.getLength();
  }
}
CompositeShape::CompositeShape(CompositeShape &&obj)
{
  if (this != &obj) {
    length_ = obj.getLength();
    shapes_.swap(obj.shapes_);
  }
}
CompositeShape &CompositeShape::operator=(const CompositeShape &rhs)
{
  if (this != &rhs) {
    length_ = 0;
    array_type copyShape(new std::shared_ptr<Shape>[rhs.getLength()]);
    for (int i = 0; i < rhs.getLength(); ++i) {
      copyShape[i] = rhs[i];
    }
    shapes_.swap(copyShape);
    length_ = rhs.getLength();
  }
  return *this;
}

std::shared_ptr<Shape> CompositeShape::operator[](const int index) const
{
  if (index < 0 || index >= length_) {
    throw std::out_of_range("Index out of range");
  }
  return shapes_[index];
}
void CompositeShape::addComponent(std::shared_ptr<Shape> shape)
{
  if (!shape) {
    throw std::invalid_argument("Object not exist");
  }
  if (this == shape.get()) {
    throw std::invalid_argument("Can not add this CompositeShape");
  }

  array_type shapes1(new std::shared_ptr<Shape>[length_ + 1]);
  for (int i = 0; i < length_; i++) {
    shapes1[i] = shapes_[i];
  }
  shapes1[length_++] = shape;
  shapes_.swap(shapes1);
}


void CompositeShape::removeComponent(const int index)
{
  checkLength();
  if (index < -1 || index >= length_) {
    throw std::out_of_range("Index out of range");
  }

  if (index == -1 && length_ > 0) {
    shapes_[length_] = nullptr;
    if (length_ > 0) {
    }
  }
  if (index < length_ && index >= 0 && length_ > 0) {
    shapes_[index] = nullptr;
    for (int i = index; i < length_ - 1; i++) {
      shapes_[i] = shapes_[i + 1];
    }
    shapes_[--length_] = nullptr;
    if (length_ > 0) {
    }

  }
}
void CompositeShape::move(const point_t &posTo)
{
  const point_t nowPos = getFrameRect().pos;
  move(posTo.x - nowPos.x, posTo.y - nowPos.y);
}
void CompositeShape::move(const double dx, const double dy)
{
  for (int i = 0; i < length_; i++) {
    shapes_[i]->move(dx, dy);
  }
}
void CompositeShape::scale(const double coefficient)
{
  if (coefficient <= 0) {
    throw std::invalid_argument("Invalid coefficient");
  }
  const point_t nowPos = getFrameRect().pos;
  for (int i = 0; i < length_; i++) {
    shapes_[i]->move({nowPos.x + coefficient * (shapes_[i]->getPosition().x - nowPos.x),
                      nowPos.y + coefficient * (shapes_[i]->getPosition().y - nowPos.y)});
    shapes_[i]->scale(coefficient);
  }
}
double CompositeShape::getArea() const
{
  checkLength();
  double area = 0;
  for (int i = 0; i < length_; i++) {
    area += shapes_[i]->getArea();
  }
  return area;
}
rectangle_t CompositeShape::getFrameRect() const
{
  checkLength();
  double left = shapes_[0]->getPosition().x - shapes_[0]->getFrameRect().width / 2;
  double right = shapes_[0]->getPosition().x + shapes_[0]->getFrameRect().width / 2;
  double top = shapes_[0]->getPosition().y + shapes_[0]->getFrameRect().height / 2;
  double bottom = shapes_[0]->getPosition().y - shapes_[0]->getFrameRect().height / 2;

  for (int i = 1; i < length_; i++) {

    double nowLeft = shapes_[i]->getPosition().x - shapes_[i]->getFrameRect().width / 2;
    double nowRight = shapes_[i]->getPosition().x + shapes_[i]->getFrameRect().width / 2;
    double nowTop = shapes_[i]->getPosition().y + shapes_[i]->getFrameRect().height / 2;
    double nowBottom = shapes_[i]->getPosition().y - shapes_[i]->getFrameRect().height / 2;
    if (nowLeft < left) {
      left = nowLeft;
    }
    if (nowRight > right) {
      right = nowRight;
    }
    if (nowTop > top) {
      top = nowTop;
    }
    if (nowBottom < bottom) {
      bottom = nowBottom;
    }
  }
  return {{(left + (right - left) / 2), (bottom + (top - bottom) / 2)}, (right - left), (top - bottom)};
}

void CompositeShape::checkLength() const
{
  if (length_ <= 0) {
    throw std::length_error("Now length of CompositeShape is 0");
  }
}
int CompositeShape::getLength() const
{
  return length_;
}
void CompositeShape::print(const std::string &name) const
{
  std::cout << name << std::endl;
  for (int i = 0; i < length_; i++) {
    shapes_[i]->print("from composite shape");
  }
}

void CompositeShape::clear()
{
  length_ = 0;
  shapes_ = std::make_unique<std::shared_ptr<Shape>[]>(0);
}
point_t CompositeShape::getPosition() const
{
  return getFrameRect().pos;
}
