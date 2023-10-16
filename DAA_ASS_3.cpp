#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


struct Item {
    int weight;
    int value;
};

bool compareItems(const Item& item1, const Item& item2) {
    return static_cast<double>(item1.value) / item1.weight > static_cast<double>(item2.value) / item2.weight;
}

double fractionalKnapsack(int capacity, std::vector<Item>& items) {
    double totalValue = 0.0;

    // Sort items in descending order of value-to-weight ratio.
    sort(items.begin(), items.end(), compareItems);

    for (const Item& item : items) {
        if (capacity == 0) {
            break;
        }

        // Take the maximum amount of the item that can fit in the knapsack.
        double taken = std::min(static_cast<double>(capacity), static_cast<double>(item.weight));

        // Update the total value and remaining capacity.
        totalValue += taken * (static_cast<double>(item.value) / item.weight);
        capacity -= taken;
    }

    return totalValue;
}

int main() {
    using namespace std; // Use the std namespace to simplify cout usage.

    int capacity = 50;
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}