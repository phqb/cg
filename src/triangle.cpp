#include "../include/triangle.h"

namespace cg {
    Triangle::Triangle() {}

    Triangle::Triangle(const Point_2 & p1, const Point_2 & p2, const Point_2 & p3) {
        this->points[0] = p1;
        this->points[1] = p2;
        this->points[2] = p3;
        this->edges[0] = Segment_2(p1, p2);
        this->edges[1] = Segment_2(p2, p3);
        this->edges[2] = Segment_2(p3, p1);
        this->edgesOppositePoint_2[0] = p3;
        this->edgesOppositePoint_2[1] = p1;
        this->edgesOppositePoint_2[2] = p2;
        this->edgeHalfPlanes[0] = HalfPlane(p1, p2, 1);
        this->edgeHalfPlanes[1] = HalfPlane(p2, p3, 1);
        this->edgeHalfPlanes[2] = HalfPlane(p3, p1, 1);
        this->edgeHalfPlanes[0].faceTo(p3);
        this->edgeHalfPlanes[1].faceTo(p1);
        this->edgeHalfPlanes[2].faceTo(p2);
    }

    long double Triangle::area() const {
        long double a = this->edges[0].length();
        long double b = this->edges[1].length();
        long double c = this->edges[2].length();
        long double p = (a + b + c)/2;
        return sqrtl(p*(p - a)*(p - b)*(p - c));
    }
}