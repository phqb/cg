#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <math.h>

using namespace std;

class Point {
	public:
		double x, y;

		void show() const;

		Point();

		Point(double x, double y);

		// Compute the distance between this and p
		// The result is not taken square root for performance purpose
		double dist2(const Point & p) const;

		// Return the middle point between this and p
		// The three points lie on the same line
		Point midPoint(const Point & p) const;
};

#endif