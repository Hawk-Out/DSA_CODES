#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void knapsackSelectedItems(int W, vector<int>& val, vector<int>& wt) {
    int n = val.size();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];

            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            }
        }
    }

    cout << "Maximum Profit: " << dp[n][W] << endl;

    cout << "Selected items: ";

    int w = W;

    for (int i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "Item" << i << " ";
            w = w - wt[i - 1];
        }
    }

    cout << endl;
}

int main() {
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;

    knapsackSelectedItems(W, val, wt);

    return 0;
}