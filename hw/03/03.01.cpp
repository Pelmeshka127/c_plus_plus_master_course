#include <algorithm>
#include <iostream>
#include <print>
#include <vector>

struct Rectangle {
    int left = 0;
    int top = 0;
    int right = 0;
    int bottom = 0;
};

int intersectionArea(const std::vector<Rectangle>& rectangles) {
    if (rectangles.empty()) {
        return 0;
    }

    Rectangle common = rectangles.front();
    for (const Rectangle& rectangle : rectangles) {
        common.left = std::max(common.left, rectangle.left);
        common.top = std::max(common.top, rectangle.top);
        common.right = std::min(common.right, rectangle.right);
        common.bottom = std::min(common.bottom, rectangle.bottom);
    }

    if (common.left >= common.right || common.top >= common.bottom) {
        return 0;
    }

    int width = common.right - common.left;
    int height = common.bottom - common.top;

    return width * height;
}

Rectangle boundingRectangle(const std::vector<Rectangle>& rectangles) {
    Rectangle result = rectangles.front();
    for (const Rectangle& rectangle : rectangles) {
        result.left = std::min(result.left, rectangle.left);
        result.top = std::min(result.top, rectangle.top);
        result.right = std::max(result.right, rectangle.right);
        result.bottom = std::max(result.bottom, rectangle.bottom);
    }
    return result;
}

int main() {
    int count = 0;
    std::cin >> count;

    std::vector<Rectangle> rectangles;
    for (int i = 0; i < count; ++i) {
        Rectangle rectangle;
        std::cin >> rectangle.left >> rectangle.top >> rectangle.right >> rectangle.bottom;
        rectangles.push_back(rectangle);
    }

    std::print("{}\n", intersectionArea(rectangles));
    if (!rectangles.empty()) {
        Rectangle bound = boundingRectangle(rectangles);
        std::print("{} {} {} {}\n", bound.left, bound.top, bound.right, bound.bottom);
    }
}
