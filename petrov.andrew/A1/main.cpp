#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{

  point_t point = {52, 45};
  Rectangle rect(point, 50, 50);
  Circle circle({100, 150}, 50);
  rect.print("Rect");
  std::cout << "Area = " << rect.getArea() << std::endl;
  circle.print("circle");
  std::cout << "Area = " << circle.getArea() << std::endl;

  std::cout << "Frame Rects" << std::endl;
  std::cout << "for rect" << " center (" << rect.getFrameRect().pos.x << ", " << rect.getFrameRect().pos.y
            << ") width = " << rect.getFrameRect().width << " height = " << rect.getFrameRect().height << std::endl;
  std::cout << "for circle" << " center (" << circle.getFrameRect().pos.x << ", " << circle.getFrameRect().pos.y
            << ") width = " << circle.getFrameRect().width << " height = " << circle.getFrameRect().height << std::endl;

  std::cout << "Move rect to (25,25)" << std::endl;
  point = {25, 25};
  rect.move(point);
  rect.print("Rect");
  std::cout << "Area = " << rect.getArea() << std::endl;
  std::cout << "Frame rect of rect" << " center (" << rect.getFrameRect().pos.x << ", "
            << rect.getFrameRect().pos.y << ") width = " << rect.getFrameRect().width
            << " height = " << rect.getFrameRect().height << std::endl;

  std::cout << "Move circle +5, -7" << std::endl;
  circle.move(5, -7);
  circle.print("Circle");
  std::cout << "Area = " << circle.getArea() << std::endl;
  std::cout << "Frame rect of  circle" << " center (" << circle.getFrameRect().pos.x << ", "
            << circle.getFrameRect().pos.y << ") width = " << circle.getFrameRect().width
            << " height = " << circle.getFrameRect().height << std::endl;
  return 0;
}
