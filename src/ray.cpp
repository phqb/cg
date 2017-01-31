#include "../include/ray.h"

Ray::Ray() {}

Ray::Ray(const Vector2 & dir, const Point & startPoint) {
	this->dir = dir;
	this->startPoint = startPoint;
}

pair<bool, Point> Ray::intersect(const Segment & s) const {
	Line rayLine(this->startPoint, this->dir.getEndPoint(this->startPoint));
	Line segLine(s.p1, s.p2);
	auto inter = rayLine.intersect(segLine);
	if (!inter.first)
		return make_pair(false, Point());
	if (this->contain(inter.second) && s.contain(inter.second))
		return inter;
	else
		return make_pair(false, Point());
}

bool Ray::contain(const Point & p) const {
	Line rayLine(this->startPoint, this->dir.getEndPoint(this->startPoint));
	if (!rayLine.contain(p))
		return false;
	Vector2 v(this->startPoint, p);
	return Compare::compare(acos(this->dir.dotProduct(p)/(this->dir.length()*v.length())), 0) == 0;
}