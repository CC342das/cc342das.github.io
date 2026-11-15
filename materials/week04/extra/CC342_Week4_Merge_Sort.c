/* CC342 Week 4 - Stable Merge Sort (C11). */
#include <stdio.h>
#include <stdlib.h>

static void merge(int a[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) temp[k++] = a[i++]; /* left wins ties */
        else temp[k++] = a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];
    for (i = left; i <= right; ++i) a[i] = temp[i];
}

static void merge_sort_range(int a[], int temp[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort_range(a, temp, left, mid);
    merge_sort_range(a, temp, mid + 1, right);
    merge(a, temp, left, mid, right);
}

static int merge_sort(int a[], int n) {
    if (n <= 1) return 1;
    int *temp = malloc((size_t)n * sizeof *temp);
    if (temp == NULL) return 0;
    merge_sort_range(a, temp, 0, n - 1);
    free(temp);
    return 1;
}

int main(void) {
    int a[] = {7, 2, 5, 3, 7, 13, 1, 6};
    int n = (int)(sizeof a / sizeof a[0]);
    if (!merge_sort(a, n)) {
        fputs("Not enough memory\n", stderr);
        return 1;
    }
    for (int i = 0; i < n; ++i) printf("%d%s", a[i], i + 1 == n ? "\n" : " ");
    return 0;
}
