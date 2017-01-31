#ifndef RAY_H
#define RAY_H

#include <math.h>
#include "point.h"
#include "segment.h"
#include "compare.h"

using namespace std;

class Ray {
	public:
		Vector2 dir;

		Point startPoint;

		Ray();

		Ray(const Vector2 & dir, const Point & startPoint);

		// Get the intersection between this ray and a segment
        // Return value is similar to Line::intersect(Line&)
        pair<bool, Point> intersect(const Segment & s) const;

        // Check if a point lie on and
        // is on the side of this ray
		bool contain(const Point & p) const;
};

#endif