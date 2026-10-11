#include <cmath>
#include <iostream>
#include <print>

int main() {
    const int capacity = 1000;
    double numbers[capacity]{};

    int count = 0;
    if (!(std::cin >> count) || count < 1 || count > capacity) {
        std::print("The count must be between 1 and {}\n", capacity);
        return 1;
    }
    for (int i = 0; i < count; ++i) {
        if (!(std::cin >> numbers[i])) {
            std::print("Invalid number\n");
            return 1;
        }
    }

    double minimum = numbers[0];
    double maximum = numbers[0];
    double sum = 0.0;

    for (int i = 0; i < count; ++i) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
        sum += numbers[i];
    }

    const double mean = sum / count;
    double sumOfSquaredDifferences = 0.0;
    for (int i = 0; i < count; ++i) {
        const double difference = numbers[i] - mean;
        sumOfSquaredDifferences += difference * difference;
    }

    const double standardDeviation = std::sqrt(sumOfSquaredDifferences / count);
    for (int pass = 0; pass < count - 1; ++pass) {
        for (int i = 0; i < count - 1 - pass; ++i) {
            if (numbers[i] > numbers[i + 1]) {
                const double temporary = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temporary;
            }
        }
    }

    double median = numbers[count / 2];
    if (count % 2 == 0) {
        median = (numbers[count / 2 - 1] + numbers[count / 2]) / 2.0;
    }

    std::print("Minimum: {}\n", minimum);
    std::print("Maximum: {}\n", maximum);
    std::print("Median: {}\n", median);
    std::print("Average: {}\n", mean);
    std::print("Standard deviation: {}\n", standardDeviation);
}
