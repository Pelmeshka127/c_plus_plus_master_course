#include <iostream>
#include <cmath>
#include <print>
#include <vector>

std::vector<double> squareSolver(double a, double b, double c) {
    const double epsilon = 0.000001;
    std::vector<double> answers;
    if (std::abs(a) <= epsilon) {
        answers.push_back(-c / b);
        return answers;
    }
    double discriminant = b * b - 4 * a * c;
    if (discriminant > epsilon) {
        answers.push_back((-b - std::sqrt(discriminant)) / (2 * a));
        answers.push_back((-b + std::sqrt(discriminant)) / (2 * a));
    } else if (std::abs(discriminant) <= epsilon) {
        answers.push_back(-b / (2 * a));
    }
    return answers;
}

int main() {
    double a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    std::vector<double> answers = squareSolver(a, b, c);
    for (double answer : answers) {
        std::print("{}\n", answer);
    }
}