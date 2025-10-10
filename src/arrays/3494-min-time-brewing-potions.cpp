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
                currMaxTime = max(currMaxTime, leastTime[i]) +
                              skill[i] * x;  // checking if the wizard is free at the currMax time
                                             // or his finishTime for previous spell is more.
            }

            leastTime[n - 1] =
                currMaxTime;  // Updating when the potion is finally brewed by the last wizard

            for (int i = n - 2; i >= 0; i--) {
                leastTime[i] =
                    leastTime[i + 1] -
                    skill[i + 1] * x;  // Updating when the previous wizards have to finish given
                                       // that the last wizard finishes with the currMaxTime.
            }
        }

        return leastTime[n - 1];
    }
};

int main() { return 0; }
