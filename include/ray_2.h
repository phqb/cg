#ifndef RAY_H
#define RAY_H

#include <cmath>
#include "point_2.h"
#include "segment_2.h"
#include "compare.h"

namespace cg {
	class Ray_2 {
		public:
			Vector_2 dir;

			Point_2 startPoint_2;

			Ray_2();

			Ray_2(const Vector_2 & dir, const Point_2 & startPoint_2);

			// Get the intersection between this ray and a segment
			// Return value is similar to Line_2::intersect(Line_2&)
			std::pair<bool, Point_2> intersect(const Segment_2 & s) const;

			// Check if a point lie on and
			// is on the side of this ray
			bool contain(const Point_2 & p) const;
	};
}

#endif