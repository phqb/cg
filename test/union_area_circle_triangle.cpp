#include <cstdio>
#include <cstdlib>

#include "../include/union.h"

int union_area_circle_triangle() {
    int testCount;
    FILE * testCountFile = fopen("test/union_area_circle_triangle_testcases/testCount.inp", "r");
    fscanf(testCountFile, "%d", &testCount);
    fclose(testCountFile);
    for (int test = 0; test < testCount; ++test) {
        char testFileName[100];
        sprintf(testFileName, "test/union_area_circle_triangle_testcases/%d.inp", test);
        FILE * testCaseFile = fopen(testFileName, "r");
        cg::Circle c;
        fscanf(testCaseFile, "%Lf %Lf %Lf\n", &c.p.x, &c.p.y, &c.r);
        cg::Point_2 p1, p2, p3;
        fscanf(testCaseFile, "%Lf %Lf\n", &p1.x, &p1.y);
        fscanf(testCaseFile, "%Lf %Lf\n", &p2.x, &p2.y);
        fscanf(testCaseFile, "%Lf %Lf\n", &p3.x, &p3.y);
        cg::Triangle trig(p1, p2, p3);
        fclose(testCaseFile);
        char myOutFileName[100];
        sprintf(myOutFileName, "test/union_area_circle_triangle_testcases/%d.my.out", test);
        FILE * testMyOut = fopen(myOutFileName, "w");
        long double answer = cg::unionArea(c, trig);
        fprintf(testMyOut, "%.10Lf", answer);
        fclose(testMyOut);
        char testOutFileName[100];
        sprintf(testOutFileName, "test/union_area_circle_triangle_testcases/%d.out", test);
        FILE * testOut = fopen(testOutFileName, "r");
        long double output;
        fscanf(testOut, "%Lf", &output);
        if (Compare::compare(output, answer) != 0) {
            printf("Failed at test %d\n", test);
            return -1;
        }
        fclose(testOut);
    }
    return 0;
}