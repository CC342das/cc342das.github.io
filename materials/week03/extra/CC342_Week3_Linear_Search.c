#include <stdio.h>

int linear_recursive(const int a[], int low, int high, int key) {
    if (low > high) return -1;
    if (a[low] == key) return low;
    return linear_recursive(a, low + 1, high, key);
}

int linear_iterative(const int a[], int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == key) return i;
    }
    return -1;
}

int main(void) {
    const int a[] = {7, 3, 9, 4, 6};
    int n = (int)(sizeof a / sizeof a[0]);
    printf("Recursive (4): %d\n", linear_recursive(a, 0, n-1, 4));
    printf("Iterative (4): %d\n", linear_iterative(a, n, 4));
    printf("Missing (2):   %d\n", linear_recursive(a, 0, n-1, 2));
    return 0;
}
