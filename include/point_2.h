#ifndef POINT_H
#define POINT_H

#include <cstdio>
#include <cmath>
#include "compare.h"

namespace cg {
	class Point_2 {
		public:
			long double x, y;

			void show() const;

			Point_2();

			Point_2(long double x, long double y);

			bool operator== (const Point_2 & p) const;

			bool operator!= (const Point_2 & p) const;

			// Compute the distance between this and p
			// The result is not taken square root for performance purpose
			long double dist2(const Point_2 & p) const;

			// Return the middle point between this and p
			// The three points lie on the same line
			Point_2 midPoint(const Point_2 & p) const;
	};
}

#endif