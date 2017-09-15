#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include <algorithm>
#include <cmath>
#include "point_2.h"
#include "segment_2.h"
#include "ray_2.h"

namespace cg {
    class ConvexPolygon {
        public:
            std::vector<Point_2> points;

            ConvexPolygon();

            ~ConvexPolygon();

            void show() const;

            void addPoint(const Point_2 & p);

            // In-place sort this polygon's points counter clockwise
            void sortCCW();

            // Compute this polygon's area
            // Note that this method only works with convex polygon
            long double area() const;

            // Check if a point is on or within this convex/concave polygon
            bool contain(const Point_2 & p) const;
    };
}

#endif