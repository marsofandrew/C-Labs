
#ifndef CIRCLE_HPP_G
#define CIRCLE_HPP_G

#include "shape.hpp"
#include <iostream>

class Circle : public Shape
{
public:

  Circle(const point_t &pos, const double rad);

  virtual double getArea() const;
  virtual rectangle_t getFrameRect() const;
  double getRadius() const;
  virtual void print(const std::string name) const override;
private:
  double radius_;
};


#endif
