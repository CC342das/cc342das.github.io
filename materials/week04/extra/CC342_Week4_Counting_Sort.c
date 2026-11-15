/* CC342 Week 4 - Stable Counting Sort for keys 1..M (C11). */
#include <stdio.h>
#include <stdlib.h>

static int counting_sort(int a[], int n, int M) {
    if (n < 0 || M < 1) return 0;
    int *count = calloc((size_t)M + 1, sizeof *count);
    int *start = calloc((size_t)M + 1, sizeof *start);
    int *out = malloc((size_t)(n ? n : 1) * sizeof *out);
    if (!count || !start || !out) {
        free(count); free(start); free(out);
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] < 1 || a[i] > M) {
            free(count); free(start); free(out);
            return 0;
        }
        ++count[a[i]];
    }
    /* Zero-based starting location of each key. */
    for (int k = 2; k <= M; ++k)
        start[k] = start[k - 1] + count[k - 1];
    /* Left-to-right placement preserves order of equal keys. */
    for (int i = 0; i < n; ++i) {
        int key = a[i];
        out[start[key]++] = key;
    }
    for (int i = 0; i < n; ++i) a[i] = out[i];
    free(count); free(start); free(out);
    return 1;
}

int main(void) {
    int a[] = {2, 3, 2, 1, 3, 2, 2, 3, 2, 2, 2, 1};
    int n = (int)(sizeof a / sizeof a[0]);
    if (!counting_sort(a, n, 3)) {
        fputs("Invalid key or allocation failure\n", stderr);
        return 1;
    }
    for (int i = 0; i < n; ++i) printf("%d%s", a[i], i + 1 == n ? "\n" : " ");
    return 0;
}
