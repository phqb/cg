#ifndef CIRCLE_H
#define CIRCLE_H

#include <cstdio>
#include <cmath>
#include "point_2.h"
#include "line_2.h"
#include "ray_2.h"
#include "segment_2.h"

namespace cg {
    class Circle {
        public:
            Point_2 p;

            long double r;

            Circle();

            Circle(const Point_2 & p, long double r);

            void show() const;

            // Get the locus of points whose distance to this circle are the same
            // The distance between a point and a circle is defined in Circle::dist2
            Line_2 radicalAxe(const Circle & c) const;

            // Compute the distance between this circle and a point
            // This distance is defined as the distance between
            // that point and a point constructed by the intersection
            // between that point and this circle
            // The result is not taken square root for performance purpose
            long double dist2(const Point_2 & p) const;

            bool contain(const Point_2 & p) const;

            bool containWithin(const Point_2 & p) const;

            bool containOn(const Point_2 & p) const;

            bool contain(const Segment_2 & s) const;

            bool containWithin(const Segment_2 & s) const;

            // Check if a point lie on or within this circle
            bool contain(const Circle & c) const;

            // Get the intersection between a line and this circle
            // The first element of returned pair denotes the number of intersection points
            // The second element of returned pair contains the intersection points
            std::pair<int, std::pair<Point_2, Point_2>> intersect(const Line_2 & l) const;

            // Get the intersection between a segment and this circle
            // The return value is similar to Circle::intersect(Line_2&)
            std::pair<int, std::pair<Point_2, Point_2>> intersect(const Segment_2 & s) const;

            // Get the intersec between a ray and this circle
            // The return value is similar to Circle::intersect(Line_2&)
            std::pair<int, std::pair<Point_2, Point_2>> intersect(const Ray_2 & l) const;

            long double area() const;

            // Get the segment area of this circle
            long double segmentArea(long double rad) const;
    };
}

#endif