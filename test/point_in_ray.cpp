#include <cstdio>

#include "../include/utils.h"
#include "../include/compare.h"

#include "../include/point.h"
#include "../include/ray.h"

int point_in_ray() {
    Utils utils;
    for (long test = 0; test < 1000000; ++test) {
        cg::Point pointA(utils.randFloat(1000), utils.randFloat(1000));
        cg::Point pointB(utils.randFloat(1000), utils.randFloat(1000));
        cg::Ray r(cg::Vector2(pointA, pointB), pointA);
        cg::Point midPoint = pointA.midPoint(pointB);
        if (!r.contain(midPoint)) {
            printf("Failed at test:\n");
            printf("Start point: "); pointA.show();
            printf("End point: "); pointB.show();
            midPoint.show();
            printf("point in ray but program don't think so\n");
            return -1;
        }
        cg::Line rLine(pointA, pointB);
        double x = pointA.x + (pointA.x < pointB.x ? -2*Compare::EPSILON : 2*Compare::EPSILON);
        cg::Point notContained(x, (-rLine.a*x - rLine.c)/rLine.b);
        if (r.contain(notContained)) {
            printf("Failed at test:\n");
            printf("Start point: "); pointA.show();
            printf("End point: "); pointB.show();
            midPoint.show();
            printf("point NOT in ray but program don't think so\n");
            return -1;
        }
    }
    return 0;
}