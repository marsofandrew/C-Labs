
#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>

Rectangle::Rectangle(const point_t &pos, const double width,
                     const double height) :
  width_(width),
  height_(height),
  position_(pos)
{
  if (height_ < 0) {
    throw std::invalid_argument("Height must be >= 0");
  }
  if (width_ < 0) {
    throw std::invalid_argument("Width must be >= 0");
  }
}
double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{


  return {position_, width_, height_};
}

double Rectangle::getHeight() const
{
  return height_;
}

double Rectangle::getWidth() const
{
  return width_;
}
void Rectangle::print(const std::string &name) const
{
  std::cout << name << std::endl;
  std::cout << "center = (" << position_.x << ", " << position_.y << ")" << std::endl;
  std::cout << "height = " << height_ << " width = " << width_ << std::endl;

}
void Rectangle::scale(const double coefficient)
{
  if (coefficient > 0) {
    width_ *= coefficient;
    height_ *= coefficient;
  } else {
    throw std::invalid_argument("Invalid Coefficient");
  }
}
void Rectangle::move(const point_t &posTo)
{
  position_ = posTo;
}

void Rectangle::move(const double dx, const double dy)
{
  position_.x += dx;
  position_.y += dy;
}
point_t Rectangle::getPosition() const
{
  return position_;
}


