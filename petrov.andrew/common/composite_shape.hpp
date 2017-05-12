//
// Created by Андрей on 13.04.2017.
//

#ifndef A3_COMPOSITE_SHAPE_HPP
#define A3_COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"

class CompositeShape : public Shape
{
public:
  using array_type = std::unique_ptr<std::shared_ptr<Shape>[]>;
  CompositeShape(std::shared_ptr<Shape> shape);
  CompositeShape(const CompositeShape &obj);
  CompositeShape(CompositeShape &&obj);
  CompositeShape &operator=(const CompositeShape &rhs);
  std::shared_ptr<Shape> operator[](const int index) const;
  void addComponent(std::shared_ptr<Shape> shape);
  void removeComponent(const int index = -1); //  if don't input index, then method will remove last component
  void clear();
  virtual void move(const point_t &posTo);
  virtual void move(const double dx, const double dy);
  virtual void scale(const double coefficient);
  virtual double getArea() const;
  rectangle_t getFrameRect() const;
  int getLength() const;
  virtual void print(const std::string &name) const;
  virtual point_t getPosition() const;
private:
  int length_;
  array_type shapes_;
  void checkLength() const;
};


#endif //A3_COMPOSITE_SHAPE_HPP


