#include <cmath>
#include <cstddef>
#include <iostream>
#include <print>

int main() {
    std::size_t capacity = 1;
    std::size_t count = 0;
    double* numbers = new double[capacity]{};

    double value = 0.0;
    while (std::cin >> value) {
        if (count == capacity) {
            const std::size_t newCapacity = capacity * 2;
            double* largerArray = new double[newCapacity]{};

            for (std::size_t i = 0; i < count; ++i) {
                largerArray[i] = numbers[i];
            }

            delete[] numbers;
            numbers = largerArray;
            capacity = newCapacity;
        }

        numbers[count] = value;
        ++count;
    }

    if (!std::cin.eof() || count == 0) {
        std::print("Enter at least one valid number\n");
        delete[] numbers;
        return 1;
    }

    double minimum = numbers[0];
    double maximum = numbers[0];
    double sum = 0.0;

    for (std::size_t i = 0; i < count; ++i) {
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
    for (std::size_t i = 0; i < count; ++i) {
        const double difference = numbers[i] - mean;
        sumOfSquaredDifferences += difference * difference;
    }
    
    const double standardDeviation = std::sqrt(sumOfSquaredDifferences / count);
    for (std::size_t pass = 0; pass < count - 1; ++pass) {
        for (std::size_t i = 0; i < count - 1 - pass; ++i) {
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

    delete[] numbers;
}
