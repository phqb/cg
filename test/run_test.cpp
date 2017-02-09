#include <cstdio>

#include "point_in_line.cpp"
#include "point_in_segment.cpp"
#include "point_in_ray.cpp"
#include "line_intersect_line.cpp"
#include "ray_intersect_segment.cpp"
#include "circle_intersect_line.cpp"
#include "circle_radical_axe.cpp"
#include "point_in_halfplane.cpp"

int main() {
    printf("Testing point in line...");
    if (point_in_line() != 0) {
        printf("Failed\n");
        return -1;
    } else
        printf("Passed\n");

    printf("Testing point in segment...");
    if (point_in_segment() != 0) {
        printf("Failed\n");
        return -1;
    } else
        printf("Passed\n");

    printf("Testing point in ray...");
    if (point_in_ray() != 0) {
        printf("Failed\n");
        return -1;
    } else
        printf("Passed\n");

    printf("Testing line intersects line...");
    if (line_intersect_line() != 0) {
        printf("Failed\n");
        return -1;
    } else
        printf("Passed\n");
    
    printf("Testing ray intersects segment...");
    if (ray_intersect_segment() != 0) {
        printf("Failed\n");
        return -1;
    } else
        printf("Passed\n");

    printf("Testing circle intersects line...");
    if (circle_intersect_line() != 0) {
        printf("Failed\n");
        return -1;
    } else
        printf("Passed\n");

    printf("Testing circle radical axe...");
    if (circle_radical_axe() != 0) {
        printf("Failed\n");
        return -1;
    } else
        printf("Passed\n");

    printf("Testing point in halfplane...");
    if (point_in_halfplane() != 0) {
        printf("Failed\n");
        return -1;
    } else
        printf("Passed\n");

    return 0;
}