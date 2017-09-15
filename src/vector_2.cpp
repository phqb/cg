#include "../include/vector_2.h"

namespace cg {
	Vector_2::Vector_2() {
		this->x = this->y = 0;
	}

	Vector_2::Vector_2(const Point_2 & p) {
		this->x = p.x;
		this->y = p.y;
	}

	Vector_2::Vector_2(long double x, long double y) {
		this->x = x;
		this->y = y;
	}

	Vector_2::Vector_2(const Vector_2 & v) {
		this->x = v.x;
		this->y = v.y;
	}

	Vector_2::Vector_2(const Point_2 & a, const Point_2 & b) {
		this->x = b.x - a.x;
		this->y = b.y - a.y;
	}

	long double Vector_2::dotProduct(const Vector_2 & v) const {
		return this->x*v.x + this->y*v.y;
	}

	long double Vector_2::crossProduct(const Vector_2 & v) const {
		long double x1 = this->x, y1 = this->y, x2 = v.x, y2 = v.y;
		return x1*y2 - x2*y1;
	}

	long double Vector_2::angle(const Vector_2 & v) const {
		long double dot = this->dotProduct(v);
		long double det = this->crossProduct(v);
		long double angle = atan2l(det, dot);
		return fabsl(angle);
	}

	long double Vector_2::length() const {
		return sqrtl(this->x*this->x + this->y*this->y);
	}

	void Vector_2::resize(long double length) {
		long double scala = length/this->length();
		this->x *= scala;
		this->y *= scala;
	}

	void Vector_2::rotate(const Point_2 & org, long double rad) {
		long double a = org.x, b = org.y, x = this->x, y = this->y;
		long double ca = cosl(rad), sa = sinl(rad);
		this->x = (x-a)*ca - (y-b)*sa + a;
		this->y = (x-a)*sa + (y-b)*ca + b;
	}

	Vector_2 Vector_2::getNorm() const {
		Vector_2 n(-this->y, this->x);
		return n;
	}

	Point_2 Vector_2::getEndPoint_2(const Point_2 & startPoint_2) const {
		return Point_2(this->x + startPoint_2.x, this->y + startPoint_2.y);
	}
}