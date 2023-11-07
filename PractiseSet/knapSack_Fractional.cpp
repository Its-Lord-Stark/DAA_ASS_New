#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

struct Item
{
    double weight;
    double profit;

};

bool compare(Item l, Item r)
{
    return (double)(l.profit/l.weight) > (double)(r.profit/r.weight);
}

int knapsack(vector<Item> &items, double capacity)
{
    double totalVal=0;

    sort(items.begin(), items.end(), compare);

    for(const Item &it: items)
    {
        if(capacity==0)
            break;
        double taken = min(it.weight, capacity);
        totalVal += (taken * (double)(it.profit/it.weight));

        capacity-=taken;
    }


    return totalVal;

}

int main()
{
    int n;
    double capacity;
    cout<<"Enter the number of items to consider"<<endl;
    cin>>n;

    cout<<"Enter the capacity"<<endl;
    cin>>capacity;


    vector<Item> items(n);

    for(int i=0;i<n;i++)
    {
        int w,p;
        cout<<"Enter element "<<i<<" weight";
        cin>>w;
        cout<<"Enter element "<<i<<" profit";
        cin>>p;

        items[i].weight =w;
        items[i].profit =p;
    }

    cout<<"The maximum profit is follow"<<endl;
    cout<<knapsack(items,capacity);

    return 0;
}