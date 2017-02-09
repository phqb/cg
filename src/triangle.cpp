#include "../include/triangle.h"

namespace cg {
    Triangle::Triangle() {}

    Triangle::Triangle(const Point & p1, const Point & p2, const Point & p3) {
        this->points[0] = p1;
        this->points[1] = p2;
        this->points[2] = p3;
        this->edges[0] = Segment(p1, p2);
        this->edges[1] = Segment(p2, p3);
        this->edges[2] = Segment(p3, p1);
        this->edgesOppositePoint[0] = p3;
        this->edgesOppositePoint[1] = p1;
        this->edgesOppositePoint[2] = p2;
    }

    double Triangle::area() const {
        double a = this->edges[0].length;
        double b = this->edges[1].length;
        double c = this->edges[2].length;
        double p = (a + b + c)/2;
        return sqrt(p*(p - a)*(p - b)*(p - c));
    }
}