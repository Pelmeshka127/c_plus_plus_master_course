#include <cstddef>
#include <print>
#include <vector>

int main() {
    const int lastStart = 100;
    std::vector<std::size_t> knownLengths(lastStart + 1, 0);
    knownLengths[1] = 1;

    std::size_t longestLength = 0;
    int longestStart = 0;

    for (int start = 1; start <= lastStart; ++start) {
        unsigned long long int value = start;
        std::size_t newSteps = 0;

        while (value >= knownLengths.size() || knownLengths[value] == 0) {
            if (value % 2 == 0) {
                value /= 2;
            } else {
                value = 3 * value + 1;
            }
            ++newSteps;
        }

        const std::size_t knownLength = knownLengths[value];
        const std::size_t length = newSteps + knownLength;
        knownLengths[start] = length;

        if (length > longestLength) {
            longestLength = length;
            longestStart = start;
        }
    }

    std::print("Start: {}\nLength: {}\n", longestStart, longestLength);
}
