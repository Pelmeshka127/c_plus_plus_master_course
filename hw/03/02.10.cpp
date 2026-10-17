#include <algorithm>
#include <cassert>
#include <numeric>
#include <utility>
#include <vector>

void insertionSort(std::vector<int>& values, int left, int right) {
    for (int i = left + 1; i < right; ++i) {
        int j = i;
        while (j > left && values[j - 1] > values[j]) {
            std::swap(values[j - 1], values[j]);
            --j;
        }
    }
}

int medianOfThree(int first, int middle, int last) {
    if (first > middle) {
        std::swap(first, middle);
    }
    if (middle > last) {
        std::swap(middle, last);
    }
    if (first > middle) {
        std::swap(first, middle);
    }
    return middle;
}

int partitionHoare(std::vector<int>& values, int left, int right) {
    int middle = std::midpoint(left, right - 1);
    int pivot = medianOfThree(values[left], values[middle], values[right - 1]);
    int i = left;
    int j = right - 1;
    while (true) {
        while (values[i] < pivot) {
            ++i;
        }
        while (values[j] > pivot) {
            --j;
        }
        if (i >= j) {
            return j + 1;
        }
        std::swap(values[i], values[j]);
        ++i;
        --j;
    }
}

void quickSortPart(std::vector<int>& values, int left, int right) {
    int insertionLimit = 16;
    if (right - left <= insertionLimit) {
        insertionSort(values, left, right);
        return;
    }
    int middle = partitionHoare(values, left, right);
    quickSortPart(values, left, middle);
    quickSortPart(values, middle, right);
}

void quickSort(std::vector<int>& values) {
    if (!values.empty()) {
        quickSortPart(values, 0, static_cast<int>(values.size()));
    }
}

int main() {
    int count = 1024;
    std::vector<int> values(count);
    for (int i = 0; i < count; ++i) {
        values[i] = count - i;
    }

    quickSort(values);
    assert(std::ranges::is_sorted(values));

}
