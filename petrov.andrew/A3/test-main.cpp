//
// Created by Андрей on 21.04.2017.
//

#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite_shape.hpp"

BOOST_AUTO_TEST_SUITE(Rectangle_Tests)

  BOOST_AUTO_TEST_CASE(Move_Test_Absolute_Rect)
  {
    Rectangle rect({10, 0}, 10, 10);
    rect.move({15, 20});
    BOOST_CHECK(rect.getPosition().x == 15 && rect.getPosition().y == 20);
  }

  BOOST_AUTO_TEST_CASE(MOVE_Test_Relative_Rect)
  {
    Rectangle rect({10, 0}, 15, 10);
    rect.move(-5, 8);
    BOOST_CHECK(rect.getPosition().x == 5 && rect.getPosition().y == 8);
  }

  BOOST_AUTO_TEST_CASE(Area_Test_Rect)
  {
    Rectangle rect({0, 0}, 15, 10);
    BOOST_REQUIRE_EQUAL(rect.getArea(), 150);
  }

  BOOST_AUTO_TEST_CASE(Area_Test_move_x_Rect)
  {
    Rectangle rect({0, 0}, 15, 10);
    rect.move(10, 0);
    BOOST_REQUIRE_EQUAL(rect.getArea(), 150);
  }

  BOOST_AUTO_TEST_CASE(Area_Test_move_y_Rect)
  {
    Rectangle rect({0, 0}, 15, 10);
    rect.move(0, 10);
    BOOST_REQUIRE_EQUAL(rect.getArea(), 150);
  }

  BOOST_AUTO_TEST_CASE(Height_Test_Rect)
  {
    Rectangle rect({0, 0}, 15, 10);
    rect.move(10, 0);
    BOOST_REQUIRE_EQUAL(rect.getHeight(), 10);
  }

  BOOST_AUTO_TEST_CASE(Widht_Test_Rect)
  {
    Rectangle rect({0, 0}, 15, 10);
    rect.move(10, 0);
    BOOST_REQUIRE_EQUAL(rect.getWidth(), 15);
  }

  BOOST_AUTO_TEST_CASE(Frame_Rect_Test_Rect)
  {
    Rectangle rect({3, 0}, 15, 10);
    BOOST_CHECK_CLOSE_FRACTION(rect.getFrameRect().width, 15, 0.00001);
    BOOST_CHECK_CLOSE_FRACTION(rect.getFrameRect().height, 10, 0.00001);
    BOOST_REQUIRE_EQUAL(rect.getFrameRect().pos.x, 3);
    BOOST_REQUIRE_EQUAL(rect.getFrameRect().pos.y, 0);
  }

  BOOST_AUTO_TEST_CASE(Scale_Test_Rect)
  {
    Rectangle rect({0, 0}, 15, 10);
    rect.scale(10);
    BOOST_REQUIRE_EQUAL(rect.getArea(), 150 * 100);
  }

  BOOST_AUTO_TEST_CASE(Inavalid_argumend_constructor_Test_Rect)
  {
    BOOST_CHECK_THROW(Rectangle({0, 0}, -10, -10), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(Invalid_argument_scale_Test_Rect)
  {
    Rectangle rect({0, 0}, 10, 10);
    BOOST_CHECK_THROW(rect.scale(-1), std::invalid_argument);
  }
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Circle_Test)

  BOOST_AUTO_TEST_CASE(Move_Test_Absolute_Circle)
  {
    Circle circle({10, 0}, 10);
    circle.move({15, 20});
    BOOST_CHECK(circle.getPosition().x == 15 && circle.getPosition().y == 20);
  }

  BOOST_AUTO_TEST_CASE(MOVE_Test_Relative_Circle)
  {
    Circle circle({10, 0}, 10);
    circle.move(-5, 8);
    BOOST_CHECK(circle.getPosition().x == 5 && circle.getPosition().y == 8);
  }

  BOOST_AUTO_TEST_CASE(Area_Test_Circle)
  {
    Circle circle({10, 0}, 10);
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), 100 * M_PI, 0.01);
  }

  BOOST_AUTO_TEST_CASE(Area_Test_move_x_Circle)
  {
    Circle circle({10, 0}, 10);
    circle.move(10, 0);
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), 100 * M_PI, 0.01);
  }

  BOOST_AUTO_TEST_CASE(Area_Test_move_y_Circle)
  {
    Circle circle({10, 0}, 10);
    circle.move(0, 10);
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), 100 * M_PI, 0.01);
  }

  BOOST_AUTO_TEST_CASE(Radius_Test_Circle)
  {
    Circle circle({10, 0}, 10);
    circle.move(0, 10);
    BOOST_REQUIRE_EQUAL(circle.getRadius(), 10);
  }


  BOOST_AUTO_TEST_CASE(Scale_Test_Circle)
  {
    Circle circle({10, 0}, 10);
    circle.scale(2);
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), 100 * M_PI * 4, 0.01);
  }

  BOOST_AUTO_TEST_CASE(Frame_Rect_Test_Circle)
  {
    Circle circle({3, 0}, 15);
    BOOST_REQUIRE_EQUAL(circle.getFrameRect().width, 30);
    BOOST_REQUIRE_EQUAL(circle.getFrameRect().height, 30);
    BOOST_REQUIRE_EQUAL(circle.getFrameRect().pos.x, 3);
    BOOST_REQUIRE_EQUAL(circle.getFrameRect().pos.y, 0);
  }

  BOOST_AUTO_TEST_CASE(Inavalid_argumend_constructor_Test_Circle)
  {
    BOOST_CHECK_THROW(Circle({0, 0}, -10), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(Invalid_argument_scale_Test_Circle)
  {
    Circle circle({0, 0}, 10);
    BOOST_CHECK_THROW(circle.scale(-1), std::invalid_argument);
  }
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE(CompositeShape_Test)

  BOOST_AUTO_TEST_CASE(Move_Test_Absolute_CS)
  {
    std::shared_ptr<Rectangle> crect0 = std::make_shared<Rectangle>(Rectangle({5, 5}, 20, 20));
    std::shared_ptr<Rectangle> crect1 = std::make_shared<Rectangle>(Rectangle({-15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect2 = std::make_shared<Rectangle>(Rectangle({15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect3 = std::make_shared<Rectangle>(Rectangle({15, -15}, 20, 20));
    std::shared_ptr<Rectangle> crect4 = std::make_shared<Rectangle>(Rectangle({-15, -15}, 20, 20));
    CompositeShape cs(crect0);
    cs.addComponent(crect1);
    cs.addComponent(crect2);
    cs.addComponent(crect3);
    cs.addComponent(crect4);
    cs.move({15, 10});
    BOOST_CHECK_CLOSE(cs.getPosition().x, 15, 0.0001);
    BOOST_CHECK_CLOSE(cs.getPosition().y, 10, 0.0001);
  }

  BOOST_AUTO_TEST_CASE(MOVE_Test_Relative_CS)
  {
    std::shared_ptr<Rectangle> crect0 = std::make_shared<Rectangle>(Rectangle({5, 5}, 20, 20));
    std::shared_ptr<Rectangle> crect1 = std::make_shared<Rectangle>(Rectangle({-10, 20}, 20, 20));
    std::shared_ptr<Rectangle> crect2 = std::make_shared<Rectangle>(Rectangle({20, 20}, 20, 20));
    std::shared_ptr<Rectangle> crect3 = std::make_shared<Rectangle>(Rectangle({20, -10}, 20, 20));
    std::shared_ptr<Rectangle> crect4 = std::make_shared<Rectangle>(Rectangle({-10, -10}, 20, 20));
    CompositeShape cs(crect0);
    cs.addComponent(crect1);
    cs.addComponent(crect2);
    cs.addComponent(crect3);
    cs.addComponent(crect4);
    cs.move(-5, 5);
    BOOST_CHECK_CLOSE(cs.getPosition().x, 0, 0.0001);
    BOOST_CHECK_CLOSE(cs.getPosition().y, 10, 0.0001);
  }

  BOOST_AUTO_TEST_CASE(Area_Test_CS)
  {
    std::shared_ptr<Rectangle> crect0 = std::make_shared<Rectangle>(Rectangle({5, 5}, 20, 20));
    std::shared_ptr<Rectangle> crect1 = std::make_shared<Rectangle>(Rectangle({-15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect2 = std::make_shared<Rectangle>(Rectangle({15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect3 = std::make_shared<Rectangle>(Rectangle({15, -15}, 20, 20));
    std::shared_ptr<Rectangle> crect4 = std::make_shared<Rectangle>(Rectangle({-15, -15}, 20, 20));
    CompositeShape cs(crect0);
    cs.addComponent(crect1);
    cs.addComponent(crect2);
    cs.addComponent(crect3);
    cs.addComponent(crect4);
    BOOST_REQUIRE_EQUAL(cs.getArea(), 2000);
  }

  BOOST_AUTO_TEST_CASE(Area_Test_move_x_CS)
  {
    std::shared_ptr<Rectangle> crect0 = std::make_shared<Rectangle>(Rectangle({5, 5}, 20, 20));
    std::shared_ptr<Rectangle> crect1 = std::make_shared<Rectangle>(Rectangle({-15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect2 = std::make_shared<Rectangle>(Rectangle({15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect3 = std::make_shared<Rectangle>(Rectangle({15, -15}, 20, 20));
    std::shared_ptr<Rectangle> crect4 = std::make_shared<Rectangle>(Rectangle({-15, -15}, 20, 20));
    CompositeShape cs(crect0);
    cs.addComponent(crect1);
    cs.addComponent(crect2);
    cs.addComponent(crect3);
    cs.addComponent(crect4);
    cs.move(5, 0);
    BOOST_REQUIRE_EQUAL(cs.getArea(), 2000);
  }

  BOOST_AUTO_TEST_CASE(Area_Test_move_y_CS)
  {
    std::shared_ptr<Rectangle> crect0 = std::make_shared<Rectangle>(Rectangle({5, 5}, 20, 20));
    std::shared_ptr<Rectangle> crect1 = std::make_shared<Rectangle>(Rectangle({-15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect2 = std::make_shared<Rectangle>(Rectangle({15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect3 = std::make_shared<Rectangle>(Rectangle({15, -15}, 20, 20));
    std::shared_ptr<Rectangle> crect4 = std::make_shared<Rectangle>(Rectangle({-15, -15}, 20, 20));
    CompositeShape cs(crect0);
    cs.addComponent(crect1);
    cs.addComponent(crect2);
    cs.addComponent(crect3);
    cs.addComponent(crect4);
    cs.move(0, 5);
    BOOST_REQUIRE_EQUAL(cs.getArea(), 2000);
  }

  BOOST_AUTO_TEST_CASE(Adder_Test_CS)
  {
    std::shared_ptr<Rectangle> crect0 = std::make_shared<Rectangle>(Rectangle({5, 5}, 20, 20));
    std::shared_ptr<Rectangle> crect1 = std::make_shared<Rectangle>(Rectangle({-15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect2 = std::make_shared<Rectangle>(Rectangle({15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect3 = std::make_shared<Rectangle>(Rectangle({15, -15}, 20, 20));
    std::shared_ptr<Rectangle> crect4 = std::make_shared<Rectangle>(Rectangle({-15, -15}, 20, 20));
    std::shared_ptr<Circle> circle = std::make_shared<Circle>(Circle({15, 10}, 25));
    CompositeShape cs(crect0);
    cs.addComponent(crect1);
    cs.addComponent(crect2);
    cs.addComponent(crect3);
    cs.addComponent(crect4);
    cs.addComponent(crect4);
    cs.addComponent(crect4);
    cs.addComponent(circle);
    cs.addComponent(crect4);
    cs.addComponent(crect4);
    cs.addComponent(crect4);
    BOOST_REQUIRE_EQUAL(cs.getLength(), 11);
  }

  BOOST_AUTO_TEST_CASE(ADDER_Invalid_argument_Error_Test_Cs)
  {
    std::shared_ptr<Rectangle> crect0 = std::make_shared<Rectangle>(Rectangle({5, 5}, 20, 20));
    std::shared_ptr<Rectangle> crect1 = std::make_shared<Rectangle>(Rectangle({-15, 15}, 20, 20));
    std::shared_ptr<CompositeShape> cs(new CompositeShape(crect0));
    cs->addComponent(crect1);
    BOOST_CHECK_THROW(cs->addComponent(cs), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(Frame_Rect_Test_CS)
  {
    std::shared_ptr<Rectangle> crect0 = std::make_shared<Rectangle>(Rectangle({0, 0}, 20, 20));
    std::shared_ptr<Rectangle> crect1 = std::make_shared<Rectangle>(Rectangle({-15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect2 = std::make_shared<Rectangle>(Rectangle({15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect3 = std::make_shared<Rectangle>(Rectangle({15, -15}, 20, 20));
    std::shared_ptr<Rectangle> crect4 = std::make_shared<Rectangle>(Rectangle({-15, -15}, 20, 20));
    CompositeShape cs(crect0);
    cs.addComponent(crect1);
    cs.addComponent(crect2);
    cs.addComponent(crect3);
    cs.addComponent(crect4);
    BOOST_REQUIRE_EQUAL(cs.getFrameRect().pos.x, 0);
    BOOST_REQUIRE_EQUAL(cs.getFrameRect().pos.y, 0);
    BOOST_REQUIRE_EQUAL(cs.getFrameRect().width, 50);
    BOOST_REQUIRE_EQUAL(cs.getFrameRect().height, 50);
  }

  BOOST_AUTO_TEST_CASE(Scale_Area_Test_CS)
  {
    std::shared_ptr<Rectangle> crect0 = std::make_shared<Rectangle>(Rectangle({0, 0}, 20, 20));
    std::shared_ptr<Rectangle> crect1 = std::make_shared<Rectangle>(Rectangle({-15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect2 = std::make_shared<Rectangle>(Rectangle({15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect3 = std::make_shared<Rectangle>(Rectangle({15, -15}, 20, 20));
    std::shared_ptr<Rectangle> crect4 = std::make_shared<Rectangle>(Rectangle({-15, -15}, 20, 20));
    CompositeShape cs(crect0);
    cs.addComponent(crect1);
    cs.addComponent(crect2);
    cs.addComponent(crect3);
    cs.addComponent(crect4);
    cs.scale(4);
    BOOST_REQUIRE_EQUAL(cs.getArea(), 2000 * 16);
  }

  BOOST_AUTO_TEST_CASE(Frame_Rect_Scale_Test_CS)
  {
    std::shared_ptr<Rectangle> crect0 = std::make_shared<Rectangle>(Rectangle({0, 0}, 20, 20));
    std::shared_ptr<Rectangle> crect1 = std::make_shared<Rectangle>(Rectangle({-15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect2 = std::make_shared<Rectangle>(Rectangle({15, 15}, 20, 20));
    std::shared_ptr<Rectangle> crect3 = std::make_shared<Rectangle>(Rectangle({15, -15}, 20, 20));
    std::shared_ptr<Rectangle> crect4 = std::make_shared<Rectangle>(Rectangle({-15, -15}, 20, 20));
    CompositeShape cs(crect0);
    cs.addComponent(crect1);
    cs.addComponent(crect2);
    cs.addComponent(crect3);
    cs.addComponent(crect4);
    cs.scale(2);
    BOOST_REQUIRE_EQUAL(cs.getFrameRect().pos.x, 0);
    BOOST_REQUIRE_EQUAL(cs.getFrameRect().pos.y, 0);
    BOOST_REQUIRE_EQUAL(cs.getFrameRect().width, 50 * 2);
    BOOST_REQUIRE_EQUAL(cs.getFrameRect().height, 50 * 2);
  }

  BOOST_AUTO_TEST_CASE(Remove_element_Test_CS)
  {
    std::shared_ptr<Rectangle> rect0 = std::make_shared<Rectangle>(Rectangle({-5, -5}, 10, 10));
    std::shared_ptr<Rectangle> rect1 = std::make_shared<Rectangle>(Rectangle({0, 0}, 10, 10));
    std::shared_ptr<Rectangle> rect2 = std::make_shared<Rectangle>(Rectangle({5, 5}, 10, 10));
    CompositeShape cs(rect0);
    cs.addComponent(rect1);
    cs.addComponent(rect2);
    cs.removeComponent(0);
    BOOST_REQUIRE_EQUAL(cs.getLength(), 2);
    BOOST_CHECK_CLOSE_FRACTION(cs.getFrameRect().pos.x, 2.5, 0.000001);
    BOOST_CHECK_CLOSE_FRACTION(cs.getFrameRect().pos.y, 2.5, 0.000001);
    BOOST_CHECK_CLOSE_FRACTION(cs.getFrameRect().width, 15, 0.000001);
    BOOST_CHECK_CLOSE_FRACTION(cs.getFrameRect().height, 15, 0.00001);
  }

  BOOST_AUTO_TEST_CASE(Get_element_Test_CS)
  {
    std::shared_ptr<Rectangle> rect0 = std::make_shared<Rectangle>(Rectangle({-5, -5}, 10, 10));
    std::shared_ptr<Rectangle> rect1 = std::make_shared<Rectangle>(Rectangle({0, 0}, 10, 10));
    std::shared_ptr<Rectangle> rect2 = std::make_shared<Rectangle>(Rectangle({5, 5}, 10, 10));
    CompositeShape cs(rect0);
    cs.addComponent(rect1);
    cs.addComponent(rect2);
    std::shared_ptr<Shape> shape = cs[0];
    BOOST_REQUIRE_EQUAL(shape->getPosition().x, -5);
    BOOST_REQUIRE_EQUAL(shape->getPosition().y, -5);
    BOOST_CHECK_CLOSE_FRACTION(shape->getFrameRect().width, 10, 0.000001);
    BOOST_CHECK_CLOSE_FRACTION(shape->getFrameRect().height, 10, 0.000001);
  }


  BOOST_AUTO_TEST_CASE(Equal_Test_CS)
  {
    std::shared_ptr<Rectangle> rect0 = std::make_shared<Rectangle>(Rectangle({-5, -5}, 10, 10));
    std::shared_ptr<Rectangle> rect1 = std::make_shared<Rectangle>(Rectangle({0, 0}, 10, 10));
    std::shared_ptr<Rectangle> rect2 = std::make_shared<Rectangle>(Rectangle({5, 5}, 10, 10));
    CompositeShape cs(rect0);
    cs.addComponent(rect1);
    cs.addComponent(rect2);
    CompositeShape shape(rect0);
    shape = cs;
    BOOST_REQUIRE_EQUAL(shape.getPosition().x, 0);
    BOOST_REQUIRE_EQUAL(shape.getPosition().y, 0);
    BOOST_CHECK_CLOSE_FRACTION(shape.getFrameRect().width, 20, 0.000001);
    BOOST_CHECK_CLOSE_FRACTION(shape.getFrameRect().height, 20, 0.000001);
  }


  BOOST_AUTO_TEST_CASE(Invalid_argument_scale_Test_CS)
  {
    std::shared_ptr<Circle> circle = std::make_shared<Circle>(Circle({0, 0}, 10));
    CompositeShape cs(circle);
    BOOST_CHECK_THROW(cs.scale(-1), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(Invalid_argument_removeComponent_Test_CS)
  {
    std::shared_ptr<Circle> circle = std::make_shared<Circle>(Circle({0, 0}, 10));
    CompositeShape cs(circle);
    BOOST_CHECK_THROW(cs.removeComponent(2), std::out_of_range);
  }

  BOOST_AUTO_TEST_CASE(Clear_Test_CS)
  {
    std::shared_ptr<Circle> circle = std::make_shared<Circle>(Circle({0, 0}, 10));
    std::shared_ptr<Circle> circle1 = std::make_shared<Circle>(Circle({5, 0}, 10));
    std::shared_ptr<Circle> circle2 = std::make_shared<Circle>(Circle({0, 5}, 10));
    CompositeShape cs(circle);
    cs.addComponent(circle1);
    cs.addComponent(circle2);
    cs.clear();

    BOOST_REQUIRE_EQUAL(cs.getLength(), 0);
  }

  BOOST_AUTO_TEST_CASE(Out_of_range_error_getComponent_Test_Cs)
  {
    std::shared_ptr<Circle> circle = std::make_shared<Circle>(Circle({0, 0}, 10));
    CompositeShape cs(circle);
    BOOST_CHECK_THROW(cs[2], std::out_of_range);
  }

  BOOST_AUTO_TEST_CASE(Add_nullptr_invalid_argument_error_Test_Cs)
  {
    std::shared_ptr<Circle> circle = nullptr;
    std::shared_ptr<Circle> circle1 = std::make_shared<Circle>(Circle({0, 0}, 10));
    CompositeShape cs(circle1);
    BOOST_CHECK_THROW(cs.addComponent(circle), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()

