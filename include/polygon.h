#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include <algorithm>
#include <cmath>
#include "point.h"
#include "segment.h"
#include "ray.h"

namespace cg {
    class Polygon {
        public:
            std::vector<Point> points;

            Polygon();

            void addPoint(const Point & p);

            // In-place sort this polygon's points counter clockwise
            void sortCCW();

            // Compute this polygon's area
            // Note that this method only works with convex polygon
            double area() const;

            // Check if a point is on or within this convex/concave polygon
            bool contain(const Point & p) const;
    };
}

#endif