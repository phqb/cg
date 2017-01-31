#ifndef VECTOR2_H
#define VECTOR2_H

#include <stdio.h>
#include <math.h>
#include "point.h"
#include "compare.h"

using namespace std;

class Vector2 : public Point {
	public:
		Vector2();

		Vector2(const Point & p);

		Vector2(double x, double y);

		Vector2(const Vector2 & v);

		Vector2(const Point & a, const Point & b);

		// Compute the dot product of this vector and v
        double dotProduct(const Vector2 & v) const;

		// Compute the cross product of this vector and v
		double crossProduct(const Vector2 & p) const;

		// Compute this vector's length
        double length() const;

		// Get a perpendicular vector of this vector
		Vector2 getNorm() const;

		// For a given start point, get the end point which
		// this vector can be contructed by
        Point getEndPoint(const Point & startPoint) const;
		
		// In-place resize this vector to a given length
		void resize(double length);
		
		// In-place rotate this vector by a origin point and angle
		void rotate(const Point & org, double rad);
};

#endif