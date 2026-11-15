/* CC342, Week 5: minimum refills on an ordered route. */
#include <stdio.h>

/* x[0] is the start; x[1..n] are stations; x[n+1] is the end. */
int min_refills(const int x[], int n, int tank,
                int selected[], int *selected_n) {
    int current = 0, refills = 0;
    *selected_n = 0;

    while (current <= n) {
        int last = current;
        while (current <= n && x[current + 1] - x[last] <= tank)
            ++current;
        if (current == last)
            return -1; /* Next station/destination is out of reach. */
        if (current <= n) {
            selected[(*selected_n)++] = x[current];
            ++refills;
        }
    }
    return refills;
}

int main(void) {
    const int x[] = {0, 200, 375, 550, 750, 950};
    const int n = 4, tank = 400;
    int selected[4], selected_n = 0;
    int result = min_refills(x, n, tank, selected, &selected_n);

    if (result < 0) {
        puts("The trip is impossible with this tank range.");
        return 0;
    }
    printf("Minimum refills: %d\nAt (km):", result);
    for (int i = 0; i < selected_n; ++i)
        printf(" %d", selected[i]);
    putchar('\n');
    return 0;
}
