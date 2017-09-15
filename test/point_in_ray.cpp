#include <cstdio>

#include "../include/utils.h"
#include "../include/compare.h"

#include "../include/point_2.h"
#include "../include/ray_2.h"

int point_in_ray() {
    Utils utils;
    for (long test = 0; test < 1000000; ++test) {
        cg::Point_2 pointA(utils.randFloat(1000), utils.randFloat(1000));
        cg::Point_2 pointB(utils.randFloat(1000), utils.randFloat(1000));
        cg::Ray_2 r(cg::Vector_2(pointA, pointB), pointA);
        cg::Point_2 midPoint = pointA.midPoint(pointB);
        if (!r.contain(midPoint)) {
            printf("Failed at test:\n");
            printf("Start point: "); pointA.show();
            printf("End point: "); pointB.show();
            midPoint.show();
            printf("point in ray but program don't think so\n");
            return -1;
        }
        cg::Line_2 rLine_2(pointA, pointB);
        long double x = pointA.x + (pointA.x < pointB.x ? -2*Compare::EPSILON : 2*Compare::EPSILON);
        cg::Point_2 notContained(x, (-rLine_2.a*x - rLine_2.c)/rLine_2.b);
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