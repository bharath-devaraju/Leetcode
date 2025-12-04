// link - https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
//Similar Questions
    //src\dp\prefixSum\1590-make-sum-divp.cpp

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int numArrays = 0;
        int curr = 0;

        vector<int> seen(k, 0);
        seen[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            curr = (((curr + nums[i]) % k) + k) % k;
            numArrays += seen[curr];
            seen[curr]++;
        }
        
        return numArrays;
    }
};

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    Solution s1;
    s1.subarraysDivbyK(nums, k);
    return 0;
}
