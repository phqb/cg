#ifndef SEGMENT_H
#define SEGMENT_H

#include <cmath>
#include "point_2.h"
#include "line_2.h"
#include "compare.h"

namespace cg {
	class Segment_2 : public Line_2 {
		public:
			Point_2 p1, p2;

			Segment_2();

			Segment_2(const Point_2 & a, const Point_2 & b);

			long double length() const;

			// Get the perpendicular line contain 
			// the middle point of this segment
			Line_2 perpendicularBisector() const;

			// Check if a point is within this segment
			bool contain(const Point_2 & p) const;
	};
}

#endif