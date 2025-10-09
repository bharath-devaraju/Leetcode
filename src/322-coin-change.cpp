#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        int minCoins = helper(coins, amount, 0);

        return minCoins == INT_MAX ? -1 : minCoins;
    }

   private:
    int helper(vector<int>& coins, int amount, int numCoins) {
        if (!amount) return numCoins;

        int minCoins = numeric_limits<int>::max();
        for (int i = 0; i < coins.size(); i++) {
            if (amount - coins[i] >= 0) {
                minCoins = min(minCoins, helper(coins, amount - coins[i], numCoins + 1));
            }
        }

        return minCoins;
    }
};

int main() {
    vector<int> coins = {1};
    int amount = 0;

    Solution s1;
    cout << s1.coinChange(coins, amount);
    return 0;
}
