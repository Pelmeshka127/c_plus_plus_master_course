#include <cassert>
#include <cmath>
#include <numbers>
#include <print>
#include <vector>

class Shape {
    public:
        virtual double perimeter() = 0;
        virtual double area() = 0;
        virtual ~Shape() = default;
    };

class Circle final : public Shape {
    private:
        double radius_;

    public:
        Circle(double radius) : radius_(radius) {}

        double perimeter() override {
            return 2.0 * std::numbers::pi * radius_;
        }

        double area() override {
            return std::numbers::pi * radius_ * radius_;
    }
};

class Polygon : public Shape {};

class Triangle : public Polygon {
    private:
        double a_;
        double b_;
        double c_;

    public:
        Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {}

        double perimeter() override {
            return a_ + b_ + c_;
        }

        double area() override {
            double halfPerimeter = perimeter() / 2.0;
            return std::sqrt(halfPerimeter *
                            (halfPerimeter - a_) *
                            (halfPerimeter - b_) *
                            (halfPerimeter - c_));
        }
};

class Rectangle : public Polygon {
    private:
        double width_;
        double height_;

    public:
        Rectangle(double width, double height) : width_(width), height_(height) {}

        double perimeter() override final {
            return 2.0 * (width_ + height_);
        }

        double area() override final {
            return width_ * height_;
        }
};

class Square final : public Rectangle {
    public:
        Square(double side) : Rectangle(side, side) {}
    };

int main() {
    Circle circle(3.0);
    Triangle triangle(3.0, 4.0, 5.0);
    Square square(4.0);

    assert(triangle.perimeter() == 12.0);
    assert(triangle.area() == 6.0);
    assert(square.perimeter() == 16.0);
    assert(square.area() == 16.0);

    std::vector<Shape*> shapes = {&circle, &triangle, &square};

    for (Shape* shape : shapes) {
        std::print("{} {}\n", shape->perimeter(), shape->area());
    }
}
