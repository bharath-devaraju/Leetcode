// link :
// https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int unqElements = 0;
        int availableVal = numeric_limits<int>::min();

        for (int i : nums) {
            int leastPossibleVal = i - k;
            int highestPossibleVal = i + k;

            if (min(leastPossibleVal, availableVal) <= highestPossibleVal) {
                unqElements++;

                // Greedily assiging the least value possible.
                // if arr = [4,4,4,4] then availableVal becomes [0, 4, 5, 6]
                // the resultant array is [3, 4, 5, 4]
                availableVal = max(leastPossibleVal, availableVal) + 1;
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
