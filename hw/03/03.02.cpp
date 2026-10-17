#include <cmath>
#include <numbers>
#include <print>

class Circle {
    private:
        double radius_;

    public:
        Circle(double radius) : radius_(radius) {}

        double perimeter() {
            return 2.0 * std::numbers::pi * radius_;
        }

        double area() {
            return std::numbers::pi * radius_ * radius_;
        }
};

class Triangle {
    private:
        double a_;
        double b_;
        double c_;
    
        public:
        Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {}

        double perimeter() {
            return a_ + b_ + c_;
        }

        double area() {
            double halfPerimeter = perimeter() / 2.0;
            return std::sqrt(halfPerimeter *
                            (halfPerimeter - a_) *
                            (halfPerimeter - b_) *
                            (halfPerimeter - c_));
        }
};

class Square {
    private:
        double side_;
        
    public:
        Square(double side) : side_(side) {}

        double perimeter() {
            return 4.0 * side_;
        }

        double area() {
            return side_ * side_;
        }
};

int main() {
    Circle circle(3.0);
    Triangle triangle(3.0, 4.0, 5.0);
    Square square(4.0);

    std::print("{} {}\n", circle.perimeter(), circle.area());
    std::print("{} {}\n", triangle.perimeter(), triangle.area());
    std::print("{} {}\n", square.perimeter(), square.area());
}
