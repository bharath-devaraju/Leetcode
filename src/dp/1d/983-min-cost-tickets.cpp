#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minCostTickets(vector<int>& days, vector<int>& costs) {
        set<int> daySet(days.begin(), days.end());
        array<int, 3> gap = {1, 7, 30};
        vector<int> dayCost(365, numeric_limits<int>::max());
        int currCost = 0;

        for (int i = 0; i < 365; i++) {
            if (!daySet.count(i + 1)) dayCost[i] = currCost;

            for (int j = 0; j < 3; j++) {
                if (i - gap[j] >= 0)
                    dayCost[i] = min(dayCost[i], costs[j] + dayCost[i - gap[j]]);
                else
                    dayCost[i] = min(dayCost[i], costs[j]);
            }

            currCost = dayCost[i];

            if (daySet.count(i + 1)) {
                daySet.erase(i + 1);
            }

            if (!daySet.size()) return dayCost[i];
        }

        return dayCost[364];
    }
};

int main() {
    Solution s1;

    vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> costs = {2, 7, 15};

    cout << s1.minCostTickets(days, costs);
    return 0;
}
