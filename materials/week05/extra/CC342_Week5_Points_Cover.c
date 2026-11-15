/* CC342, Week 5: cover points using the fewest unit segments. */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

static int compare_double(const void *p, const void *q) {
    double a = *(const double *)p, b = *(const double *)q;
    return (a > b) - (a < b);
}

size_t cover_points(double points[], size_t n) {
    qsort(points, n, sizeof points[0], compare_double);
    size_t i = 0, segments = 0;

    while (i < n) {
        double left = points[i], right = left + 1.0;
        ++segments;
        printf("Segment %zu: [%.1f, %.1f]\n", segments, left, right);
        do {
            ++i;
        } while (i < n && points[i] <= right);
    }
    return segments;
}

int main(void) {
    double ages[] = {7.7, 5.0, 9.6, 6.0, 7.2, 8.1, 5.5};
    size_t n = sizeof ages / sizeof ages[0];
    size_t answer = cover_points(ages, n);
    printf("Minimum groups/segments: %zu\n", answer);
    return 0;
}
