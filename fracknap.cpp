#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Structure to store item details
struct Item {
    int value;
    int weight;
};
// Comparator function to sort items by value/weight ratio (descending)
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate maximum value in Fractional Knapsack
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Step 1: Sort items by decreasing value/weight ratio
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
// Step 2: Pick items greedily
    for (int i = 0; i < items.size(); i++) {
        // If whole item can be taken
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        // Take fraction of the item
        else {
            totalValue += items[i].value * 
                          ((double)capacity / items[i].weight);
            break; // Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int capacity = 50;
    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };
    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in Knapsack = " << maxValue << endl;
    return 0;
}