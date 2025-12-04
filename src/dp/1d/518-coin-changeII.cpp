// link :
// https://leetcode.com/problems/coin-change-ii/description/?envType=problem-list-v2&envId=x1k8lxi5

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    using ull = unsigned long long;
    int change(int amount, vector<int>& coins) {
        int c = coins.size();
        vector<ull> temp(amount + 1, 0LL);
        temp[0] = 1;
        for (int i = 0; i < c; i++) {
            for (int amt = 1; amt <= amount; amt++) {
                if (amt >= coins[i]) {
                    temp[amt] += temp[amt - coins[i]];
                }
            }
        }

        return temp[amount];
    }
};

int main() {
    Solution s1;

    vector<int> coins = {2};
    cout << s1.change(3, coins);
    return 0;
}
