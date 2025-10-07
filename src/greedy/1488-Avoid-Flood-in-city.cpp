#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> recentIndex;
        set<int> zeroIndex;

        for (size_t i = 0; i < rains.size(); i++) {
            if (rains[i]) {
                if (recentIndex.count(rains[i])) {
                    auto index = find_if(zeroIndex.begin(), zeroIndex.end(),
                                         [&](int curr) { return recentIndex[rains[i]] < curr; });

                    if (index == zeroIndex.end()) return vector<int>();

                    rains[*index] = rains[i];
                    zeroIndex.erase(index);
                }
                recentIndex[rains[i]] = i;
                rains[i] = -1;
            }

            else {
                zeroIndex.insert(i);
            }
        }

        for (const int i : zeroIndex) {
            rains[i] = 1;
        }

        return rains;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> rains(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> rains[i];
    }

    Solution s1;
    vector<int> result = s1.avoidFlood(rains);

    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}
