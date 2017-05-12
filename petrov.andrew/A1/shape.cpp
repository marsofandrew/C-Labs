
#include <iostream>
#include "shape.hpp"


Shape::Shape(const point_t pos) :
  position_(pos)
{
}
void Shape::move(const point_t &posTo)
{
  position_ = posTo;
}

void Shape::move(const double dx, const double dy)
{
  position_.x += dx;
  position_.y += dy;
}
point_t Shape::getPosition() const
{
  return position_;
}
void Shape::print(const std::string name) const
{
  std::cout << name << std::endl;
  std::cout << "center = (" << position_.x << ", " << position_.y << ")" << std::endl;
}

