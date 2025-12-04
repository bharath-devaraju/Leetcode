// link: leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    using ll = long long;

    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<ll> leastTime;

        for (int x : mana) {
            ll currMaxTime = 0;
            for (int i = 0; i < n; i++) {
                // checking if the wizard is free at the currMax time
                // or his finishTime for previous spell is more.

                currMaxTime = max(currMaxTime, leastTime[i]) + skill[i] * x;
            }

            leastTime[n - 1] =
                currMaxTime;  // Updating when the potion is finally brewed by the last wizard

            for (int i = n - 2; i >= 0; i--) {
                // Updating when the previous wizards have to finish given
                // that the last wizard finishes with the currMaxTime.

                leastTime[i] = leastTime[i + 1] - skill[i + 1] * x;
            }
        }

        return leastTime[n - 1];
    }
};

int main() { return 0; }
