#include "../include/circle.h"

Circle::Circle() {}

Circle::Circle(const Point & p, double r) {
	this->p = p;
	this->r = r;
}

void Circle::show() const {
	printf("(%lf, %lf), %lf\n", this->p.x, this->p.y, this->r);
}

double Circle::dist2(const Point & p) const {
	return this->p.dist2(p) - this->r*this->r;
}

Line Circle::radicalAxe(const Circle & c) const {
	Vector2 p1p2(this->p, c.p);
	double l = sqrt(this->p.dist2(c.p));
	double l1 = (l*l + this->r*this->r - c.r*c.r)/(2*l);
	Vector2 vl1(p1p2);
	vl1.resize(l1);
	Point midPoint = vl1.getEndPoint(this->p);
	Line ret(midPoint, vl1);
	return ret;
}

bool Circle::contain(const Circle & c) const {
	double d = sqrt(this->p.dist2(c.p));
	return Compare::compare(this->r - c.r, d) >= 0;
}

pair<int, pair<Point, Point>> Circle::intersect(const Line & l) const {
	Line perLine = l.perpendicular(this->p);
	auto inter = l.intersect(perLine);
	double d2 = this->p.dist2(inter.second);
	if (Compare::compare(this->r*this->r, d2) == 0)
		return make_pair(1, make_pair(inter.second, Point()));
	else if (this->r*this->r > d2) {
		double d = sqrt(this->r*this->r - d2);
		Vector2 p(-l.b, l.a);
		p.resize(d);
		Point i1 = p.getEndPoint(inter.second);
		p.rotate(Point(0, 0), M_PI);
		Point i2 = p.getEndPoint(inter.second);
		return make_pair(2, make_pair(i1, i2));
	} else
		return make_pair(0, make_pair(Point(), Point()));
}

pair<int, pair<Point, Point>> Circle::intersect(const Ray & r) const {
	Line rayLine(r.startPoint, r.dir.getEndPoint(r.startPoint));
	auto inters = this->intersect(rayLine);
	if (inters.first == 0)
		return make_pair(0, make_pair(Point(), Point()));
	if (inters.first == 1)
		return 
			r.contain(inters.second.first) ?
			make_pair(1, inters.second) :
			make_pair(0, make_pair(Point(), Point()));
	return inters;
}

double Circle::segmentArea(double rad) const {
	return this->r*this->r*(rad - sin(rad))/2;
}