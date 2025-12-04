#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        vector<vector<int>> dpTable(n, vector<int>(n, 0));

        return Helper(nums, dpTable, 0, n - 1, x, n);
    }

   private:
    int Helper(vector<int>& nums, vector<vector<int>>& memo, int left, int right, int x, int n) {
        if (!x) return 0;

        int left_min = n;
        int right_min = n;

        if (memo[left][right]) return memo[left][right];

        if (nums[left] <= x) left_min = 1 + Helper(nums, memo, left + 1, right, x - nums[left], n);

        if (nums[right] <= x)
            right_min = 1 + Helper(nums, memo, left, right - 1, x - nums[right], n);

        memo[left][right] = min(left_min, right_min);

        return memo[left][right];
    }
};

int main() { return 0; }
