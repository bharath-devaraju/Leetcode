#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        if (!amount) return 0;

        int maxInt = INT_MAX / 2;
        vector<int> dp(amount + 1, maxInt);
        dp[0] = 0;

        for (int amt = 1; amt <= amount; amt++) {
            for (int c : coins) {
                if (c > amt) continue;
                dp[amt] = min(dp[amt], 1 + dp[amt - c]);
            }
        }

        int result = dp[amount];
        return result >= maxInt ? -1 : result;
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution s1;
    cout << s1.coinChange(coins, amount);
    return 0;
}
