#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include "point_2.h"
#include "segment_2.h"
#include "halfplane.h"

namespace cg {
    class Triangle {
        public:
            Point_2 points[3];
            
            Segment_2 edges[3];

            Point_2 edgesOppositePoint_2[3];

            HalfPlane edgeHalfPlanes[3];

            Triangle();

            Triangle(const Point_2 & p1, const Point_2 & p2, const Point_2 & p3);

            long double area() const;
    };
}

#endif