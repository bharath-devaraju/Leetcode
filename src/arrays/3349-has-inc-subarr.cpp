// link :
// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/?envType=daily-question&envId=2025-10-14

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int currLen = 0, prevLen = 0;
        int maxLen = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] > 0)
                currLen++;
            else {
                prevLen = currLen;
                currLen = 1;
            }

            maxLen = max(maxLen, max(currLen / 2, min(currLen, prevLen)));
            if (maxLen >= k) return true;
        }

        return false;
    }
};
int main() {
    vector<int> nums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};

    Solution s1;
    cout << s1.hasIncreasingSubarrays(nums, 3);
    return 0;
}
