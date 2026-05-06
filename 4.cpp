#include <bits/stdc++.h>
using namespace std;

int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for (int i = nums.size() - 1; i >= 2; i--) {
        int a = nums[i - 2];
        int b = nums[i - 1];
        int c = nums[i];

        if (a + b > c) {
            return a + b + c;
        }
    }

    return 0;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << largestPerimeter(nums);

    return 0;
}