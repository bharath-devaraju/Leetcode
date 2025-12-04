// link :
// https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int unqElements = 0;
        int prevVal = numeric_limits<int>::min();

        for (int i : nums) {
            int leastVal = i - k;
            int maxVal = i + k;

            if (min(leastVal, prevVal) <= maxVal) {
                unqElements++;
                prevVal = max(leastVal, prevVal) + 1;
            }
        }

        return unqElements;
    }
};

int main() {
    vector<int> nums = {7, 8, 10, 10, 7, 6, 7};
    Solution s1;
    cout << s1.maxDistinctElements(nums, 1);
    return 0;
}
