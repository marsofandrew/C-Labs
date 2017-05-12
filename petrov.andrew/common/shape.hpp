
#ifndef INC_1_SHAPE_HPP
#define INC_1_SHAPE_HPP

#include "base-types.hpp"
#include <iostream>

class Shape
{
public:
  virtual ~Shape() = default;
  virtual void move(const point_t &posTo) = 0;
  virtual void move(const double dx, const double dy) = 0;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual point_t getPosition() const = 0;
  virtual void print(const std::string &name) const = 0;
  virtual void scale(const double coefficient) = 0;


};

#endif


