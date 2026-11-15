/* CC342, Week 5: largest number from single digits. */
#include <stdio.h>
#include <stddef.h>

int main(void) {
    const int digits[] = {3, 9, 5, 9, 7, 1};
    const size_t n = sizeof digits / sizeof digits[0];
    int count[10] = {0};

    for (size_t i = 0; i < n; ++i) {
        if (digits[i] < 0 || digits[i] > 9) {
            puts("Error: inputs must be single digits (0-9).");
            return 1;
        }
        ++count[digits[i]];
    }

    printf("Largest arrangement: ");
    for (int d = 9; d >= 0; --d) {
        for (int k = 0; k < count[d]; ++k)
            putchar('0' + d);
    }
    putchar('\n');
    return 0;
}
