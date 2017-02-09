#include "../include/compare.h"

const double Compare::EPSILON = 0.000000001;
const double Compare::ARC_EPSILON = 0.0000001;

int Compare::compare(const double a, const double b) {
    return fabs(a - b) < Compare::EPSILON ? 0 : (a > b ? 1 : -1);
}

int Compare::arcCompare(const double a, const double b) {
    return fabs(a - b) < Compare::ARC_EPSILON ? 0 : (a > b ? 1 : -1);
}