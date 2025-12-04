// link -
// https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        int minDiff = numeric_limits<int>::max();

        set<int> visited;

        for (int i = x; i < n; i++) {
            visited.insert(nums[i - x]);

            auto it = visited.lower_bound(nums[i]);

            int lowerBound = (it != visited.end()) ? *it : INT_MAX;
            int upperBound = (it != visited.begin()) ? *(--it) : INT_MAX;

            minDiff = min(minDiff, min(abs(lowerBound - nums[i]), abs(nums[i] - upperBound)));
            if (!minDiff) return 0;
        }

        return minDiff;
    }
};

int main() {
    Solution s1;

    vector<int> nums = {1, 2, 3, 4};
    int x = 3;

    cout << s1.minAbsoluteDifference(nums, x);
    return 0;
}
