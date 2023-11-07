#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


struct Item {
    int weight;
    int value;
};

bool compareItems(const Item& item1, const Item& item2) {
    return (double)(item1.value) / item1.weight > (double)(item2.value) / item2.weight;
}

double fractionalKnapsack(int capacity, std::vector<Item>& items) {
    double totalValue = 0.0;

    sort(items.begin(), items.end(), compareItems);

    for (const Item& item : items) {
        if (capacity == 0) {
            break;
        }

        double taken = min((double)(capacity), (double)(item.weight));

        totalValue += taken * ((double)(item.value) / item.weight);
        capacity -= taken;
    }

    return totalValue;
}

int main() {
    using namespace std; 
    int n;
    cout<<"No.of items:"<<endl;
    cin>>n;

    int capacity;
    cout<<"Enter capacity: "<<endl;
    cin>>capacity;


    vector<Item> items(n);
    for(int i=0;i<n;i++)
    {
        int profit;
        int weight;
        cout<<"Item "<<i<<" Weight"<<endl;
        cin>>weight;
        items[i].weight = weight;

        cout<<"Item "<<i<<" value"<<endl;
        cin>>profit;
        items[i].value = profit;
    }

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}