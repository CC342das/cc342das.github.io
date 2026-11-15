#include <stdio.h>

int binary_recursive(const int a[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (a[mid] == key) return mid;
    if (key < a[mid]) return binary_recursive(a, low, mid-1, key);
    return binary_recursive(a, mid+1, high, key);
}

int binary_iterative(const int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) return mid;
        if (key < a[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main(void) {
    const int a[] = {3, 5, 8, 10, 12, 15, 18, 20, 20, 50, 60};
    int n = (int)(sizeof a / sizeof a[0]);
    printf("Recursive (50): %d\n", binary_recursive(a, 0, n-1, 50));
    printf("Iterative (50): %d\n", binary_iterative(a, n, 50));
    printf("Missing (17):   %d\n", binary_iterative(a, n, 17));
    return 0;
}
