#include "../include/compare.h"

const long double Compare::EPSILON = 0.000000001;
const long double Compare::ARC_EPSILON = 0.0000001;

int Compare::compare(const long double a, const long double b) {
    return fabsl(a - b) < Compare::EPSILON ? 0 : (a > b ? 1 : -1);
}

int Compare::arcCompare(const long double a, const long double b) {
    return fabsl(a - b) < Compare::ARC_EPSILON ? 0 : (a > b ? 1 : -1);
}