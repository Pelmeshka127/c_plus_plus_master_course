#include <iostream>
#include <print>

int main() {
    double epsilon = 0.0;
    if (!(std::cin >> epsilon) || epsilon <= 0.0) {
        std::print("Enter a positive epsilon\n");
        return 1;
    }

    // Leibniz series: pi / 4 = 1 - 1/3 + 1/5 - 1/7 + ...
    double piQuarter = 0.0;
    double denominator = 1.0;
    double sign = 1.0;
    while (1.0 / denominator >= epsilon) {
        piQuarter += sign / denominator;
        sign = -sign;
        denominator += 2.0;
    }
    const double pi = 4.0 * piQuarter;

    // Maclaurin series: e = 1 + 1/1! + 1/2! + ...
    double e = 0.0;
    double term = 1.0;
    int index = 0;
    while (term >= epsilon) {
        e += term;
        ++index;
        term /= index;  
    }
    std::print("pi = {}\ne = {}\n", pi, e);
}
