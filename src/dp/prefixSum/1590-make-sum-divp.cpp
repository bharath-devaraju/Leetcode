// link - https://leetcode.com/problems/make-sum-divisible-by-p/description/ #include

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minSubarray(vector<int>& nums, int p) {
        int minLen = nums.size();
        int reqRem = accumulate(nums.begin(), nums.end(), 0LL) % p;
        int curr = 0;
        unordered_map<int, int> seen;

        if (reqRem == 0) return 0;

        seen.insert({0, -1});

        for (int i = 0; i < nums.size(); i++) {
            curr = (curr + nums[i]) % p;
            int val = curr - reqRem;
            int complementary = (val % p + p) % p;
            if (seen.count(complementary)) minLen = min(minLen, i - seen[complementary]);

            seen[curr] = i;
        }

        return minLen == nums.size() ? -1 : minLen;
    }
};

int main() { return 0; }
