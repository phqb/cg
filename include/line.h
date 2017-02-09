#ifndef LINE_H
#define LINE_H

#include <cstdio>
#include <cmath>
#include <utility>
#include "point.h"
#include "vector2.h"
#include "compare.h"

namespace cg {
	class Line {
		public:
			double a, b, c;

			Line();

			Line(double a, double b, double c);

			Line(const Point & a, const Point & b);

			Line(const Point & a, const Vector2 & v);

			void show() const;

			// Chec if a point is on this line
			bool contain(const Point & p) const;

			double dist(const Point & p) const;

			// Compute the intersection of this line and l
			// Return <true, intersection> if it exist a intersection point
			// otherwise, return <false, _>
			std::pair<bool, Point> intersect(const Line & l) const;

			// Get the perpendicular line of this line
			Line perpendicular(const Point & p) const;
	};
}

#endif