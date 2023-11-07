#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>&weights, vector<int>&profit, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = capacity; w >= weights[i]; w--) {
            dp[w] = max(dp[w], profit[i] + dp[w - weights[i]]);
        }
    }

    return dp[capacity];
}

int main() {
    int n;
    cout<<"Enter number of items "<<endl;
    cin>>n;

    int capacity;
    cout<<"Enter capacity "<<endl;
    cin>>capacity;

    vector<int> weights(n);
    vector<int> profit(n);

    for(int i=0;i<n;i++)
    {
        int profit1;
        int weight;
        cout<<"Item "<<i<<" Weight"<<endl;
        cin>>weight;
        weights.push_back(weight);
        cout<<"Item "<<i<<" profit"<<endl;
        cin>>profit1;
        profit.push_back(profit1);
    }

    int answer = knapsack(weights, profit, capacity);
    cout << answer;

    return 0;

}

