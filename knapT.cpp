#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsackUtil(int i, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
    if (i == 0 || W == 0) {
        return 0;
    }

    if (dp[i][W] != -1) {
        return dp[i][W];
    }

    if (wt[i - 1] > W) {
        dp[i][W] = knapsackUtil(i - 1, W, val, wt, dp);
    } else {
        int excludeItem = knapsackUtil(i - 1, W, val, wt, dp);

        int includeItem = val[i - 1] + knapsackUtil(i - 1, W - wt[i - 1], val, wt, dp);

        dp[i][W] = max(includeItem, excludeItem);
    }

    return dp[i][W];
}

int knapsack(int W, vector<int>& val, vector<int>& wt) {
    int n = val.size();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    return knapsackUtil(n, W, val, wt, dp);
}

int main() {
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;

    cout << knapsack(W, val, wt) << endl;

    return 0;
}