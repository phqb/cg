#include <cstdio>
#include <cstdlib>

#include "../include/union.h"

int union_area_circle_polygon() {
    long testCount;
    FILE * testCountFile = fopen("test/union_area_circle_polygon_testcases/testCount.inp", "r");
    fscanf(testCountFile, "%ld", &testCount);
    fclose(testCountFile);
    for (long test = 0; test < testCount; ++test) {
        char testFileName[100];
        sprintf(testFileName, "test/union_area_circle_polygon_testcases/%ld.inp", test);
        FILE * testCaseFile = fopen(testFileName, "r");
        cg::Circle c;
        fscanf(testCaseFile, "%lf %lf %lf\n", &(c.p.x), &(c.p.y), &(c.r));
        long pointsCount;
        cg::Polygon pl;
        fscanf(testCaseFile, "%ld\n", &pointsCount);
        for (long point = 0; point < pointsCount; ++point) {
            double x, y;
            fscanf(testCaseFile, "%lf %lf\n", &x, &y);
            pl.addPoint(cg::Point(x, y));
        }        
        fclose(testCaseFile);
        char myOutFileName[100];
        sprintf(myOutFileName, "test/union_area_circle_polygon_testcases/%ld.my.out", test);
        FILE * testMyOut = fopen(myOutFileName, "w");
        pl.sortCCW();
        fprintf(testMyOut, "%.10lf", cg::unionArea(c, pl));
        fclose(testMyOut);
    }
    return 0;
}