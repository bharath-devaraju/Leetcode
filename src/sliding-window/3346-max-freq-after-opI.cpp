// link -
// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/?envType=daily-question&envId=2025-10-21

// Similar
// src\sliding-window\3347-max-freq-after-opII.cpp

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

        int minEle = nums[0];
        int maxEle = nums[n - 1];

        int maxFreq = 0;
        int currFreq = 0;

        for (int i = minEle; i <= maxEle; i++) {
            auto left = lower_bound(nums.begin(), nums.end(), i - k);
            auto right = upper_bound(nums.begin(), nums.end(), i + k);

            int diff = distance(left, right);

            int elemToChange = min(diff - freqCount[i], numOperations);

            currFreq = freqCount[i] + elemToChange;

            maxFreq = min(maxFreq, currFreq);
        }

        return maxFreq;
    }

    // Better Solution
    /* int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> freqCount;
        int n = nums.size();
        int maxFreq = 0;

        for (int i : nums) {
            freqCount[i]++;
        }

        for (int i = 0, l = 0, r = 0; i < n; i++) {
            //lower Bound
            while (l < n && nums[l] < nums[i] - k) l++;

            //Upper bound
            while (r < n && nums[r] <= nums[i] + k) r++;

            int numChange = r - l - freqCount[nums[i]];
            maxFreq = max(maxFreq, min(numChange, numOperations) + freqCount[nums[i]]);
        }

        for (int i = 0, j = 0; j < n; j++) {
            while (nums[i] + k < nums[j] - k) {
                i++;
            }
            maxFreq = max(maxFreq, min(j - i + 1, numOperations));
        }

        return maxFreq;
    } */
};

int main() { return 0; }
