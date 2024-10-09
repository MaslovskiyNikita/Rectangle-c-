#pragma once
#include <cmath>

class Point2 {
private:
    double x;
    double y;
public:
    Point2() {};
    Point2(double x_, double y_) : x(x_), y(y_) {};
    double GetX() { return x; };
    double GetY() { return y; };

    double distance(Point2& other) {
        return std::sqrt(std::pow(other.GetX() - x, 2) + std::pow(other.GetY() - y, 2));
    }
};
