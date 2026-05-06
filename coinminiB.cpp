#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCoins(vector<int>& coins, int sum) {
    const int INF = 1e9;

    vector<int> dp(sum + 1, INF);

    dp[0] = 0;

    for (int coin : coins) {
        for (int j = coin; j <= sum; j++) {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    if (dp[sum] == INF) {
        return -1;
    }

    return dp[sum];
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 5;

    cout << minCoins(coins, sum) << endl;

    return 0;
}