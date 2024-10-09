#pragma once
#include "Point2.h"
#include <iostream>

class Rectangle {
private:
    Point2 HightLeftPoint;
    Point2 BottomLeftPoint;
    Point2 BottomRightPoint;
    Point2 HightRightPoint;

    double topSide;
    double leftSide;
    double bottomSide;
    double rightSide;
    double perimetr;
    double HightLeftDiagonal;
    double BottomLeftDiagonal;
    double area;

public:
    Rectangle() {};
    Rectangle(Point2 HightLeftPoint_, Point2 BottomLeftPoint_, Point2 BottomRightPoint_, Point2 HightRightPoint_)
        : HightLeftPoint(HightLeftPoint_), BottomLeftPoint(BottomLeftPoint_), BottomRightPoint(BottomRightPoint_), HightRightPoint(HightRightPoint_) {
        topSide = HightLeftPoint.distance(HightRightPoint);
        leftSide = HightLeftPoint.distance(BottomLeftPoint);
        bottomSide = BottomLeftPoint.distance(BottomRightPoint);
        rightSide = HightRightPoint.distance(BottomRightPoint);
        perimetr = topSide + leftSide + bottomSide + rightSide;
        HightLeftDiagonal = HightLeftPoint.distance(BottomRightPoint);
        BottomLeftDiagonal = BottomLeftPoint.distance(HightRightPoint);

    }

    double GetTopSide() { return topSide; };
    double GetLeftSide() { return leftSide; };
    double GetBottomSide() { return bottomSide; };
    double GetRightSide() { return rightSide; };
    double GetPerimetr() { return perimetr; };
    double GetHightLeftDiagonal() { return HightLeftDiagonal; };
    double GetBottomLeftDiagonal() { return BottomLeftDiagonal; };

    double GetArea() {
        double x1 = HightLeftPoint.GetX(), y1 = HightLeftPoint.GetY();
        double x2 = HightRightPoint.GetX(), y2 = HightRightPoint.GetY();
        double x3 = BottomRightPoint.GetX(), y3 = BottomRightPoint.GetY();
        double x4 = BottomLeftPoint.GetX(), y4 = BottomLeftPoint.GetY();

        return std::abs((x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1 - x2 * y1 - x3 * y2 - x4 * y3 - x1 * y4) / 2.0);
    }

    bool isValid() {
        if (HightLeftPoint.GetX() == BottomLeftPoint.GetX() && HightLeftPoint.GetY() == BottomLeftPoint.GetY() ||
            HightLeftPoint.GetX() == HightRightPoint.GetX() && HightLeftPoint.GetY() == HightRightPoint.GetY() ||
            BottomLeftPoint.GetX() == BottomRightPoint.GetX() && BottomLeftPoint.GetY() == BottomRightPoint.GetY() ||
            HightRightPoint.GetX() == BottomRightPoint.GetX() && HightRightPoint.GetY() == BottomRightPoint.GetY()) {
            throw std::runtime_error("ETO NE CHETIROHYGOLNIK");
        }
        return true;
    }
};