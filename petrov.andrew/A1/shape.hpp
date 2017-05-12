
#ifndef INC_1_SHAPE_HPP
#define INC_1_SHAPE_HPP

#include "base-types.hpp"
#include <iostream>

class Shape
{
public:
  virtual void move(const point_t &posTo);

  virtual void move(const double dx, const double dy);

  virtual double getArea() const = 0;

  virtual rectangle_t getFrameRect() const = 0;
  point_t getPosition() const;
  virtual void print(std::string name) const;

protected:

  Shape(const point_t pos);
  point_t position_;
};

#endif
