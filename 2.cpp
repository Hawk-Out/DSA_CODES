//Botttom Up

#include <iostream>
#include <vector>
using namespace std;

//Driver Code Ends
int count(vector<int>& coins, int sum) {
int n = coins.size();
vector<vector<int> > dp(n + 1, vector<int>(sum + 1, 0));
  dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
// Add the number of ways to make change without
// using the current coin,
    dp[i][j] += dp[i - 1][j];
    if ((j - coins[i - 1]) >= 0) {
// Add the number of ways to make change
// using the current coin
    dp[i][j] += dp[i][j - coins[i - 1]];
           }
        }
    }

        return dp[n][sum];
}
    int main() {
     vector<int> coins = {1, 2, 3};
     int sum = 5;
     cout << count(coins, sum);
    return 0;
}
