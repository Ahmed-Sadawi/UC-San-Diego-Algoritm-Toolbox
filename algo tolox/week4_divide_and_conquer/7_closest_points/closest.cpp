#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <limits>

struct Point {
    int x, y;
};

bool cmpX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool cmpY(const Point& a, const Point& b) {
    return a.y < b.y;
}

double dist(const Point& a, const Point& b) {
    return std::hypot(a.x - b.x, a.y - b.y);
}

double brute_force(const std::vector<Point>& points, int left, int right) {
    double min_dist = std::numeric_limits<double>::max();
    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j < right; ++j) {
            min_dist = std::min(min_dist, dist(points[i], points[j]));
        }
    }
    return min_dist;
}

double strip_closest(std::vector<Point>& strip, double d) {
    std::sort(strip.begin(), strip.end(), cmpY);
    double min_dist = d;
    int n = strip.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < min_dist; ++j) {
            min_dist = std::min(min_dist, dist(strip[i], strip[j]));
        }
    }

    return min_dist;
}

double closest_util(std::vector<Point>& points_sorted_by_x, int left, int right) {
    if (right - left <= 3) {
        return brute_force(points_sorted_by_x, left, right);
    }

    int mid = left + (right - left) / 2;
    Point mid_point = points_sorted_by_x[mid];

    double d_left = closest_util(points_sorted_by_x, left, mid);
    double d_right = closest_util(points_sorted_by_x, mid, right);
    double d = std::min(d_left, d_right);

    std::vector<Point> strip;
    for (int i = left; i < right; ++i) {
        if (std::abs(points_sorted_by_x[i].x - mid_point.x) < d) {
            strip.push_back(points_sorted_by_x[i]);
        }
    }

    return std::min(d, strip_closest(strip, d));
}

double minimal_distance(std::vector<int> x, std::vector<int> y) {
    int n = x.size();
    std::vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        points[i] = {x[i], y[i]};
    }

    std::sort(points.begin(), points.end(), cmpX);
    return closest_util(points, 0, n);
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> x(n), y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    std::cout << std::fixed << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
