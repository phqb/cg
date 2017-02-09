#ifndef SEGMENT_H
#define SEGMENT_H

#include <cmath>
#include "point.h"
#include "line.h"
#include "compare.h"

namespace cg {
	class Segment : public Line {
		public:
			Point p1, p2;

			Segment();

			Segment(const Point & a, const Point & b);

			double length() const;

			// Get the perpendicular line contain 
			// the middle point of this segment
			Line perpendicularBisector() const;

			// Check if a point is within this segment
			bool contain(const Point & p) const;
	};
}

#endif