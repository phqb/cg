#include "../include/vector2.h"

namespace cg {
	Vector2::Vector2() {}

	Vector2::Vector2(const Point & p) {
		this->x = p.x;
		this->y = p.y;
	}

	Vector2::Vector2(double x, double y) {
		this->x = x;
		this->y = y;
	}

	Vector2::Vector2(const Vector2 & v) {
		this->x = v.x;
		this->y = v.y;
	}

	Vector2::Vector2(const Point & a, const Point & b) {
		this->x = b.x - a.x;
		this->y = b.y - a.y;
	}

	double Vector2::dotProduct(const Vector2 & v) const {
		return this->x*v.x + this->y*v.y;
	}

	double Vector2::crossProduct(const Vector2 & v) const {
		double x1 = this->x, y1 = this->y, x2 = v.x, y2 = v.y;
		return x1*y2 - x2*y1;
	}

	double Vector2::angle(const Vector2 & v) const {
		double dot = this->dotProduct(v);
		double det = this->x*v.y - this->y*v.x;
		double angle = atan2(det, dot);
		return fabs(angle);
	}

	double Vector2::length() const {
		return sqrt(this->x*this->x + this->y*this->y);
	}

	void Vector2::resize(double length) {
		double scala = length/this->length();
		this->x *= scala;
		this->y *= scala;
	}

	void Vector2::rotate(const Point & org, double rad) {
		double a = org.x, b = org.y, x = this->x, y = this->y;
		double ca = cos(rad), sa = sin(rad);
		this->x = (x-a)*ca - (y-b)*sa + a;
		this->y = (x-a)*sa + (y-b)*ca + b;
	}

	Vector2 Vector2::getNorm() const {
		Vector2 n(-this->y, this->x);
		return n;
	}

	Point Vector2::getEndPoint(const Point & startPoint) const {
		return Point(this->x + startPoint.x, this->y + startPoint.y);
	}
}