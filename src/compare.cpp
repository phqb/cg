#include "../include/compare.h"

const double Compare::EPSILON = 0.000000001;

int Compare::compare(const double a, const double b) {
    return fabs(a - b) < Compare::EPSILON ? 0 : (a > b ? 1 : -1);
}