
#include "circle.hpp"
#include <math.h>


Circle::Circle(const point_t &pos, const double rad) :
  Shape(pos),
  radius_(rad)
{
  if (radius_ < 0) {
    radius_ = 0;
    std::cerr << "Error radius can't be <= 0 " << std::endl;
  }
}


double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}
rectangle_t Circle::getFrameRect() const
{
  return {position_, 2 * radius_, 2 * radius_};
}
double Circle::getRadius() const
{
  return radius_;
}
void Circle::print(const std::string name) const
{
  Shape::print(name);
  std::cout << "Radius = " << radius_ << std::endl;

}

