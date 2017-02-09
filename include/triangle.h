#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include "point.h"
#include "segment.h"

namespace cg {
    class Triangle {
        public:
            Point points[3];
            Segment edges[3];
            Point edgesOppositePoint[3];

            Triangle();

            Triangle(const Point & p1, const Point & p2, const Point & p3);

            double area() const;
    };
}

#endif