/* CC342 Week 4 - Selection Sort (C11). */
#include <stdio.h>

static void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_index]) min_index = j;
        }
        if (min_index != i) {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
}

int main(void) {
    int a[] = {8, 4, 2, 5, 2};
    int n = (int)(sizeof a / sizeof a[0]);
    selection_sort(a, n);
    for (int i = 0; i < n; ++i) printf("%d%s", a[i], i + 1 == n ? "\n" : " ");
    return 0;
}
