#include "Rectangle.h"

class Parallelogram : public Rectangle {
public:
    Parallelogram() {};
    Parallelogram(Point2 HightLeftPoint_, Point2 BottomLeftPoint_, Point2 BottomRightPoint_, Point2 HightRightPoint_)
        : Rectangle(HightLeftPoint_, BottomLeftPoint_, BottomRightPoint_, HightRightPoint_) {}

    bool isParallelogram() {
        if (!isValid()) {
            throw std::runtime_error("ETO NE CHETIROHYGOLNIK");
        }

        double topSide = GetTopSide();
        double bottomSide = GetBottomSide();
        double leftSide = GetLeftSide();
        double rightSide = GetRightSide();

        return (topSide == bottomSide && leftSide == rightSide);
    }
};
