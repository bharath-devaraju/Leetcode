// link -
// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/?envType=daily-question&envId=2025-10-21

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        unordered_map<int, int> freqCount;

        for (int i : nums) {
            freqCount[i]++;
        }

        int minEle = nums.front();  // Finally all the converted
        int maxEle = nums.back();   // elements must lie in this range.

        int maxFreq = 0;
        int currFreq = 0;

        for (int i = minEle; i <= maxEle; i++) {
            // finding the first element that is less that or equal to i - k
            auto left = lower_bound(nums.begin(), nums.end(), i - k);

            // finding the first element that is greater than to i + k
            auto right = upper_bound(nums.begin(), nums.end(), i + k);

            // difference between the iterators
            int diff = distance(left, right);

            // maximum number of non similar elements that can be converted to i
            int elemToChange = min(diff - freqCount[i], numOperations);

            currFreq = freqCount[i] + elemToChange;

            maxFreq = min(maxFreq, currFreq);
        }

        return maxFreq;
    }
};

int main() { return 0; }
