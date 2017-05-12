
#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite_shape.hpp"
#include <cmath>

int main()
{
  std::shared_ptr<Rectangle> rect0 = std::make_shared<Rectangle>(Rectangle({0, 0}, 5, 5));
  std::shared_ptr<Rectangle> rect1 = std::make_shared<Rectangle>(Rectangle({5, 5}, 5, 5));
  std::shared_ptr<Rectangle> rect2 = std::make_shared<Rectangle>(Rectangle({-5, -5}, 5, 5));
  CompositeShape compositeShape(rect0);
  compositeShape.addComponent(rect1);
  compositeShape.addComponent(rect2);
  compositeShape.print("from Cs");
  compositeShape.removeComponent(0);
  compositeShape.print("from Cs1");
  std::shared_ptr<Shape> el = compositeShape[0];
  el = nullptr;
  compositeShape.print("from Cs2");
  compositeShape[0] = nullptr;
  compositeShape.print("from Cs3");
  CompositeShape compositeShape1(compositeShape);
  compositeShape1.addComponent(rect0);
  compositeShape.print("cs 0");
  compositeShape1.print("cs 1");
  CompositeShape cs(rect0);
  CompositeShape ccc(compositeShape1);
  cs = compositeShape1;
  ccc.print("test");
  cs.print("cs 2");
  CompositeShape cs5(std::move(compositeShape));
  cs5.print("cs 5");
  //compositeShape.print("test 1");// this string have error - it's normal
  return 0;
}

