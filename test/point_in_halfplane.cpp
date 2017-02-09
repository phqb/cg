#include <cstdio>

#include "../include/utils.h"
#include "../include/compare.h"

#include "../include/point.h"
#include "../include/halfplane.h"

int point_in_halfplane() {
    Utils utils;
    for (int test = 0; test < 1000000; ++test) {
        int side = utils.randFloat(1000) > 0 ? 1 : -1;
        cg::HalfPlane hl1(cg::Point(utils.randFloat(1000), utils.randFloat(1000)), cg::Point(utils.randFloat(1000), utils.randFloat(1000)), side);
        cg::HalfPlane hl2(hl1.a, hl1.b, hl1.c, -side);
        cg::Point p(utils.randFloat(1000), utils.randFloat(1000));
        if (hl1.contain(p) ^ hl2.contain(p) == false || hl1.contain(p) && hl2.contain(p)) {
            return -1;
        }
    }
    return 0;
}