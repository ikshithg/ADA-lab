#include <stdio.h>

// Structure to store item details
struct Item {
    int value;
    int weight;
    float ratio;
};

// Function to sort items by value/weight ratio (descending)
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

// Function to calculate maximum value
float fractionalKnapsack(struct Item items[], int n, int capacity) {
    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take full item
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take fraction of item
            totalValue += items[i].ratio * capacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items by ratio
    sortItems(items, n);

    float maxValue = fractionalKnapsack(items, n, capacity);

    printf("Maximum value in knapsack = %.2f\n", maxValue);

    return 0;
}
