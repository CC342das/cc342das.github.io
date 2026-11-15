/* CC342 Week 4 - Quicksort with randomized three-way partition (C11). */
#include <stdio.h>
#include <stdlib.h>

static void swap(int *x, int *y) {
    int tmp = *x; *x = *y; *y = tmp;
}

static void quick_sort(int a[], int left, int right) {
    while (left < right) {
        /* This randomized-pivot demonstration uses rand() % range. */
        int pivot = a[left + rand() % (right - left + 1)];
        int lt = left, i = left, gt = right;
        while (i <= gt) {
            if (a[i] < pivot) swap(&a[lt++], &a[i++]);
            else if (a[i] > pivot) swap(&a[i], &a[gt--]);
            else ++i;
        }
        /* Recurse on the smaller region to keep stack depth O(log n). */
        if (lt - left < right - gt) {
            quick_sort(a, left, lt - 1);
            left = gt + 1;
        } else {
            quick_sort(a, gt + 1, right);
            right = lt - 1;
        }
    }
}

int main(void) {
    int a[] = {6, 4, 8, 2, 9, 3, 9, 4, 7, 6, 1};
    int n = (int)(sizeof a / sizeof a[0]);
    srand(42u); /* fixed seed makes classroom output reproducible */
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) printf("%d%s", a[i], i + 1 == n ? "\n" : " ");
    return 0;
}
