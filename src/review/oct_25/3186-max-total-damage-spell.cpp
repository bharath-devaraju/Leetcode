
// link : https://leetcode.com/problems/maximum-total-damage-with-spell-casting/
// link : https://leetcode.com/problems/maximum-total-damage-with-spell-casting/

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    using ll = long long;
    long long maximumTotalDamage(vector<int>& power) {
        const size_t n = power.size();
        sort(power.begin(), power.end());
        ll *maxDamage = new ll[n], maxDp = 0LL, damage = 0LL;

        for (int i = n - 1, j = n - 1; i >= 0; i--) {
            maxDamage[i] = power[i];

            if (i != n - 1 && power[i] == power[i + 1]) maxDamage[i] = power[i] + maxDamage[i + 1];

            // Calculating maxDp from reverse for every element (similar to largest subsequence)
            else {
                while (power[j] - power[i] > 2) {
                    maxDp = max(maxDp, maxDamage[j]);
                    j--;
                }
                maxDamage[i] = power[i] + maxDp;
            }

            damage = max(damage, maxDamage[i]);
        }

        return damage;
    }
};

int main() {
    vector<int> power = {1, 1, 3, 4};

    Solution s1;
    cout << s1.maximumTotalDamage(power);
    return 0;
}
