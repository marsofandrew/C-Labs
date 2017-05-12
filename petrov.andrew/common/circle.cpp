
#include "circle.hpp"
#include <math.h>
#include <stdexcept>

Circle::Circle(const point_t &pos, const double rad) :
  radius_(rad),
  position_(pos)
{
  if (radius_ < 0) {
    throw std::invalid_argument("radius cant be <0");
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
void Circle::print(const std::string &name) const
{
  std::cout << name << std::endl;
  std::cout << "center = (" << position_.x << ", " << position_.y << ")" << std::endl;
  std::cout << "Radius = " << radius_ << std::endl;

}

void Circle::scale(const double coefficient)
{
  if (coefficient > 0) {
    radius_ *= coefficient;
  } else {
    throw std::invalid_argument("Invalid Coefficient");
  }
}
void Circle::move(const point_t &posTo)
{
  position_ = posTo;
}

void Circle::move(const double dx, const double dy)
{
  position_.x += dx;
  position_.y += dy;
}
point_t Circle::getPosition() const
{
  return position_;
}

