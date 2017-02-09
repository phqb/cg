#include <cstdio>

#include "../include/utils.h"
#include "../include/compare.h"

#include "../include/point.h"
#include "../include/line.h"

int point_in_line() {
    Utils utils;
    for (long test = 0; test < 1000000; ++test) {
        cg::Point pointA(utils.randFloat(1000), utils.randFloat(1000));
        cg::Point pointB(utils.randFloat(1000), utils.randFloat(1000));
        cg::Line line(pointA, pointB);
        if (!line.contain(pointA)) {
            printf("Failed at test:\n");
            pointA.show();
            line.show();
            printf("point in line but program don't think so\n");
            return -1;
        }
        if (!line.contain(pointB)) {
            printf("Failed at test:\n");
            pointB.show();
            line.show();
            printf("point in line but program don't think so\n");
            return -1;
        }
        cg::Line anotherLine(line.a, line.b, line.c + 2*Compare::EPSILON);
        double x = utils.randFloat(1000);
        cg::Point notContained(x, (-anotherLine.a*x - anotherLine.c)/anotherLine.b);
        if (line.contain(notContained)) {
            printf("Failed at test:\n");
            notContained.show();
            line.show();
            printf("point NOT in line but program don't think so\n");
            return -1;
        }
    }
    return 0;
}