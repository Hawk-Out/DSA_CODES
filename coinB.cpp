#include <iostream>
#include <vector>
using namespace std;

int countWays(vector<int>& coins, int sum) {
    vector<int> dp(sum + 1, 0);

    dp[0] = 1;

    for (int i = 0; i < coins.size(); i++) {
        for (int j = coins[i]; j <= sum; j++) {
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }

    return dp[sum];
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 4;

    cout << countWays(coins, sum);

    return 0;
}