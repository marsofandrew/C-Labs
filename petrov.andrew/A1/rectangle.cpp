
#include "rectangle.hpp"


Rectangle::Rectangle(const point_t &pos, const double width, const double height) :
  Shape(pos),
  width_(width),
  height_(height)
{
  if (height_ <= 0) {
    height_ = 0;
    std::cerr << "Error height can't be <=0 " << std::endl;
  }
  if (width_ <= 0) {
    width_ = 0;
    std::cerr << "Error widht can't be <=0 " << std::endl;
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
void Rectangle::print(const std::string name) const
{
  Shape::print(name);
  std::cout << "height = " << height_ << " width = " << width_ << std::endl;

}

