#ifndef HALFPLANE_H
#define HALFPLANE_H

#include <cmath>
#include <vector>
#include "point_2.h"
#include "line_2.h"
#include "compare.h"
#include "convex_polygon.h"

namespace cg {
	class HalfPlane : public Line_2 {
		public:
			int side;

			HalfPlane();

			HalfPlane(const Line_2 & l, int side);

			HalfPlane(const Point_2 & a, const Point_2 & b, int side);

			HalfPlane(long double a, long double b, long double c, int side);

			// Check if a point is on this half-plane or is within its side
			bool contain(const Point_2 & p) const;

			void faceTo(const Point_2 & p);

			// Compute the intersection of half-planes
			// If this intersection is closed, it forms a convex polygon
			// If this intersection is unbounded, a 4 boundary half-planes can be used to close it
			// Complexity: O(n^3), which n = no. of half-planes
			static ConvexPolygon halfPlanesIntersect(const std::vector<HalfPlane> & hl);
	};
}

#endif