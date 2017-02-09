#ifndef UNION_H
#define UNION_H

#include <cmath>
#include <utility>
#include "polygon.h"
#include "circle.h"
#include "compare.h"
#include "halfplane.h"
#include "vector2.h"
#include "triangle.h"

namespace cg {
    double unionArea(const Cirlce & c, const Point & p1, const Point & p2, const Point & p3);

    double unionArea(const Circle & c, const Polygon & pl);

    double unionArea(const Circle & c, const HalfPlane & hl);
}

#endif