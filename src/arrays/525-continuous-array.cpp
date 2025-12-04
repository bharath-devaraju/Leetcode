// link - https://leetcode.com/problems/contiguous-array/description/

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int currSum = 0;
        unordered_map<int, int> seen;
        seen.insert({0, -1});
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            currSum = currSum + (nums[i] ? 1 : -1);

            if (seen.count(currSum))
                maxLen = max(maxLen, i - seen[currSum]);
            else
                seen[currSum] = i;
        }

        return maxLen;
    }
};

int main() {
    vector<int> nums = {0, 1, 1, 1, 1, 1, 0, 0, 0};
    Solution s1;
    s1.findMaxLength(nums);
    return 0;
}
