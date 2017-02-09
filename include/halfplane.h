#ifndef HALFPLANE_H
#define HALFPLANE_H

#include <cmath>
#include <vector>
#include "point.h"
#include "line.h"
#include "compare.h"
#include "polygon.h"

namespace cg {
	class HalfPlane : public Line {
		public:
			int side;

			HalfPlane();

			HalfPlane(const Line & l, int side);

			HalfPlane(const Point & a, const Point & b, int side);

			HalfPlane(double a, double b, double c, int side);

			// Check if a point is on this half-plane or is within its side
			bool contain(const Point & p) const;

			// Compute the intersection of half-planes
			// If this intersection is closed, it forms a convex polygon
			// If this intersection is unbounded, a 4 boundary half-planes can be used to close it
			// Complexity: O(n^3), which n = no. of half-planes
			static Polygon halfPlanesIntersect(const std::vector<HalfPlane> & hl);
	};
}

#endif