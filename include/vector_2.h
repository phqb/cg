#ifndef VECTOR2_H
#define VECTOR2_H

#include <cstdio>
#include <cmath>
#include "point_2.h"
#include "compare.h"

namespace cg {
	class Vector_2 : public Point_2 {
		public:
			Vector_2();

			Vector_2(const Point_2 & p);

			Vector_2(long double x, long double y);

			Vector_2(const Vector_2 & v);

			Vector_2(const Point_2 & a, const Point_2 & b);

			// Compute the dot product of this vector and v
			long double dotProduct(const Vector_2 & v) const;

			// Compute the cross product of this vector and v
			long double crossProduct(const Vector_2 & p) const;

			// Compute the angle between this vector and v
			// 0 <= angle <= pi/2
			long double angle(const Vector_2 & v) const;

			// Compute this vector's length
			long double length() const;

			// Get a perpendicular vector of this vector
			Vector_2 getNorm() const;

			// For a given start point, get the end point which
			// this vector can be contructed by
			Point_2 getEndPoint_2(const Point_2 & startPoint_2) const;
			
			// In-place resize this vector to a given length
			void resize(long double length);
			
			// In-place rotate this vector by a origin point and angle
			void rotate(const Point_2 & org, long double rad);
	};
}

#endif