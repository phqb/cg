#ifndef LINE_H
#define LINE_H

#include <cstdio>
#include <cmath>
#include <utility>
#include "point_2.h"
#include "vector_2.h"
#include "compare.h"

namespace cg {
	class Line_2 {
		public:
			long double a, b, c;

			Line_2();

			Line_2(long double a, long double b, long double c);

			Line_2(const Point_2 & a, const Point_2 & b);

			Line_2(const Point_2 & a, const Vector_2 & v);

			void show() const;

			// Chec if a point is on this line
			bool contain(const Point_2 & p) const;

			long double dist(const Point_2 & p) const;

			// Compute the intersection of this line and l
			// Return <true, intersection> if it exist a intersection point
			// otherwise, return <false, _>
			std::pair<bool, Point_2> intersect(const Line_2 & l) const;

			// Get the perpendicular line of this line
			Line_2 perpendicular(const Point_2 & p) const;
	};
}

#endif