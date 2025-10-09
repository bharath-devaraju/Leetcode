// link : https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxEnergy = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            if (i + k < n) energy[i] += energy[i + k];

            maxEnergy = max(maxEnergy, energy[i]);
        }

        return maxEnergy;
    }
};

int main() {
    vector<int> energy = {5, 2, -10, -5, 1};
    int k = 3;

    Solution s1;
    cout << s1.maximumEnergy(energy, k);
    return 0;
}
