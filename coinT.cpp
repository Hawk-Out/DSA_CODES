#include <iostream>
#include <vector>
using namespace std;

int solve(int i, int sum, vector<int>& coins, vector<vector<int>>& dp) {
    // If sum becomes 0, we found 1 valid way
    if (sum == 0) {
        return 1;
    }

    // If no coins left, but sum is not 0
    if (i == coins.size()) {
        return 0;
    }

    // If already calculated
    if (dp[i][sum] != -1) {
        return dp[i][sum];
    }

    // Option 1: Do not take current coin
    int notTake = solve(i + 1, sum, coins, dp);

    // Option 2: Take current coin
    int take = 0;

    if (coins[i] <= sum) {
        take = solve(i, sum - coins[i], coins, dp);
    }

    // Total ways = take + not take
    dp[i][sum] = take + notTake;

    return dp[i][sum];
}

int countWays(vector<int>& coins, int sum) {
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    return solve(0, sum, coins, dp);
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 4;

    cout << countWays(coins, sum);

    return 0;
}