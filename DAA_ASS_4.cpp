#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> weights, vector<int> profit, int capacity) {
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
    int capacity = 50;
    vector<int> weights = {10, 20, 30};
    vector<int> profit = {60, 100, 120};

    int answer = knapsack(weights, profit, capacity);
    cout << answer;

    return 0;
}