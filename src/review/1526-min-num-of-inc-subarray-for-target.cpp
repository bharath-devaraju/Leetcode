// link -
// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/?envType=daily-question&envId=2025-10-30&roomId=TwGGQO

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minNumberOperations(vector<int>& target) {
        int numOperations = 0;
        vector<int> diffArray(target.size(), 0);

        diffArray[0] = target[0];

        for (int i = 1; i < target.size(); i++) {
            diffArray[i] = diffArray[i - 1] + target[i];
        }

        for (int i = 0; i < target.size(); i++) {
        }

        return 0;
    }
};

int main() { return 0; }
