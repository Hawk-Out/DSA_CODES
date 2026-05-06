#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void minCoinsUsed(vector<int>& coins, int sum) {
    const int INF = 1e9;

    vector<int> dp(sum + 1, INF);
    vector<int> used(sum + 1, -1);

    dp[0] = 0;

    for (int coin : coins) {
        for (int j = coin; j <= sum; j++) {
            if (dp[j - coin] + 1 < dp[j]) {
                dp[j] = dp[j - coin] + 1;
                used[j] = coin;
            }
        }
    }

    if (dp[sum] == INF) {
        cout << "Not possible" << endl;
        return;
    }

    cout << "Minimum coins: " << dp[sum] << endl;
    cout << "Coins used: ";

    int current = sum;

    while (current > 0) {
        cout << used[current] << " ";
        current = current - used[current];
    }

    cout << endl;
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 5;

    minCoinsUsed(coins, sum);

    return 0;
}