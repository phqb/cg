#ifndef CIRCLE_H
#define CIRCLE_H

#include <stdio.h>
#include <math.h>
#include "point.h"
#include "line.h"
#include "ray.h"

using namespace std;

class Circle {
	public:
		Point p;

		double r;

		Circle();

		Circle(const Point & p, double r);

		void show() const;

        // Get the locus of points whose distance to this circle are the same
        // The distance between a point and a circle is defined in Circle::dist2
		Line radicalAxe(const Circle & c) const;

        // Compute the distance between this circle and a point
        // This distance is defined as the distance between
        // that point and a point constructed by the intersection
        // between that point and this circle
        // The result is not taken square root for performance purpose
		double dist2(const Point & p) const;

        // Check if a point lie on or within this circle
		bool contain(const Circle & c) const;

        // Get the intersec between a line and this circle
        // The first element of returned pair denotes the number of intersection points
        // The second element of returned pair contains the intersection points
		pair<int, pair<Point, Point>> intersect(const Line & l) const;

        // Get the intersec between a ray and this circle
        // The return value is similar to Circle::intersect(Line&)
		pair<int, pair<Point, Point>> intersect(const Ray & l) const;

        // Get the segment area of this circle
		double segmentArea(double rad) const;
};

#endif