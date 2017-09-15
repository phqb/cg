#ifndef UNION_H
#define UNION_H

#include <cmath>
#include <utility>
#include <tuple>
#include "convex_polygon.h"
#include "circle.h"
#include "compare.h"
#include "halfplane.h"
#include "vector_2.h"
#include "triangle.h"

namespace cg {
    long double unionArea(const Circle & c, const Triangle & trig);

    long double unionArea(const Circle & c, const ConvexPolygon & pl);

    long double unionArea(const Circle & c, const HalfPlane & hl);
}

#endif