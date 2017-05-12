
#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include <cmath>

int main()
{
  Rectangle rect({5,5},10,10);
  std::cout << "Area (rect) before scale = " << rect.getArea() << std::endl;
  rect.scale(2);
  std::cout << "k = 2, Area (rect) after scale = " << rect.getArea() << std::endl;
  Circle circle({5,2},10);
  std::cout << "Area (circle) before scale = " << circle.getArea() << std::endl;
  circle.scale(2);
  std::cout << "k = 2, Area (circle) after scale = " << circle.getArea() << std::endl;
  return 0;

}


