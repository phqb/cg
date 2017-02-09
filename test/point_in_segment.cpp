#include <cstdio>

#include "../include/utils.h"
#include "../include/compare.h"

#include "../include/point.h"
#include "../include/segment.h"

int point_in_segment() {
    Utils utils;
    for (long test = 0; test < 1000000; ++test) {
        cg::Point pointA(utils.randFloat(1000), utils.randFloat(1000));
        cg::Point pointB(utils.randFloat(1000), utils.randFloat(1000));
        cg::Segment s(pointA, pointB);
        cg::Point midPoint = pointA.midPoint(pointB);
        if (!s.contain(midPoint)) {
            printf("Failed at test:\n");
            s.show();
            printf("Start point: "); pointA.show();
            printf("End point: "); pointB.show();
            midPoint.show();
            printf("point in segment but program don't think so\n");
            return -1;
        }
        {
            double x = pointA.x + (pointA.x < pointB.x ? -2*Compare::EPSILON : 2*Compare::EPSILON);
            cg::Point notContained(x, (-s.a*x - s.c)/s.b);
            if (s.contain(notContained)) {
                printf("Failed at test:\n");
                s.show();
                printf("Start point: "); pointA.show();
                printf("End point: "); pointB.show();
                midPoint.show();
                printf("point NOT in segment but program don't think so\n");
                return -1;
            }
        }
        {
            double x = pointB.x + (pointA.x < pointB.x ? 2*Compare::EPSILON : -2*Compare::EPSILON);
            cg::Point notContained(x, (-s.a*x - s.c)/s.b);
            if (s.contain(notContained)) {
                printf("Failed at test:\n");
                s.show();
                printf("Start point: "); pointA.show();
                printf("End point: "); pointB.show();
                midPoint.show();
                printf("point NOT in segment but program don't think so\n");
                return -1;
            }
        }
    }
    return 0;
}