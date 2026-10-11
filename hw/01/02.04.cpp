#include <print>

int main() {
    for (int hundreds = 1; hundreds <= 9; hundreds++) {
        for (int tens = 0; tens <= 9; tens++) {
            for (int ones = 0; ones <= 9; ones++) {
                int number = 100 * hundreds + 10 * tens + ones;
                int sumOfCubes = hundreds * hundreds * hundreds + tens * tens * tens + ones * ones * ones;
                if (number == sumOfCubes) {
                    std::print("{}\n", number);
                }
            }
        }
    }
}
