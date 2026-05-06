#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int minCoinsUtil(int sum, vector<int>& coins, vector<int>& dp) {
    if (sum == 0) {
        return 0;
    }

    if (sum < 0) {
        return INF;
    }

    if (dp[sum] != -1) {
        return dp[sum];
    }

    int ans = INF;

    for (int coin : coins) {
        ans = min(ans, minCoinsUtil(sum - coin, coins, dp) + 1);
    }

    dp[sum] = ans;

    return dp[sum];
}

int minCoins(vector<int>& coins, int sum) {
    vector<int> dp(sum + 1, -1);

    int ans = minCoinsUtil(sum, coins, dp);

    if (ans >= INF) {
        return -1;
    }

    return ans;
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 5;

    cout << minCoins(coins, sum) << endl;

    return 0;
} 