
#ifndef RECTANGLE_HPP_G
#define RECTANGLE_HPP_G

#include "shape.hpp"
#include <iostream>

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &pos, const double width, const double height);
  virtual double getArea() const;
  virtual rectangle_t getFrameRect() const;
  double getWidth() const;
  double getHeight() const;
  virtual void print(const std::string &name) const;
  virtual void scale(const double coefficient);
  point_t getPosition() const;
  virtual void move(const double dx, const double dy);
  virtual void move(const point_t &posTo);
private:
  double width_;
  double height_;
  point_t position_;

};

#endif


