#include <iostream>
#include <numeric>
#include <print>

int recursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return recursive(b, a % b);
}

int iterative(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {
    int a = 0;
    int b = 0;
    std::cin >> a >> b;

    int recursiveGcd = recursive(a, b);
    int iterativeGcd = iterative(a, b);

    long long lcm = a / iterativeGcd;
    lcm *= b;

    if (recursiveGcd != std::gcd(a, b) ||
        iterativeGcd != std::gcd(a, b) ||
        lcm != std::lcm(static_cast<long long>(a), b)) {
        std::print("Validation failed.\n");
        return 1;
    }

    std::print("Recursive GCD: {}\nIterative GCD: {}\nLCM: {}\n",recursiveGcd, iterativeGcd, lcm);
}