/* CC342, Week 5: fractional knapsack by value/weight. */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct { int id; double weight, value; } Item;

static int compare_density(const void *p, const void *q) {
    const Item *a = p, *b = q;
    double x = a->value / a->weight;
    double y = b->value / b->weight;
    return (x < y) - (x > y); /* Decreasing density. */
}

double fractional_knapsack(Item items[], size_t n, double capacity) {
    qsort(items, n, sizeof items[0], compare_density);
    double total = 0.0;

    for (size_t i = 0; i < n && capacity > 0.0; ++i) {
        double take = items[i].weight < capacity ? items[i].weight : capacity;
        double gained = take * items[i].value / items[i].weight;
        total += gained;
        capacity -= take;
        printf("Item %d: take %.1f kg, gain $%.1f\n",
               items[i].id, take, gained);
    }
    return total;
}

int main(void) {
    Item items[] = {{1, 4.0, 20.0}, {2, 3.0, 18.0}, {3, 2.0, 14.0}};
    size_t n = sizeof items / sizeof items[0];
    double answer = fractional_knapsack(items, n, 7.0);
    printf("Maximum value: $%.1f\n", answer);
    return 0;
}
