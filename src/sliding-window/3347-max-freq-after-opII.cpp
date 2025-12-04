// link -
// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/?envType=daily-question&envId=2025-10-22

// Similar
//\\src\sliding-window\3347-max-freq-after-opII.cpp

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> freqCount;
        int n = nums.size();
        int maxFreq = 0;

        for (int i : nums) {
            freqCount[i]++;
        }

        // Case 1 - Considering the most frequent final element to already exist in the array.
        for (int i = 0, l = 0, r = 0; i < n; i++) {
            // lower Bound
            while (l < n && nums[l] < nums[i] - k) l++;

            // Upper bound
            while (r < n && nums[r] <= nums[i] + k) r++;

            int numChange = r - l - freqCount[nums[i]];
            maxFreq = max(maxFreq, min(numChange, numOperations) + freqCount[nums[i]]);
        }

        // Case 2 - The most frequent element isn't already in the array and several elements must
        // be changed.
        for (int i = 0, j = 0; j < n; j++) {
            // Finding if a range of elements be converted to the same element.
            // The particular element they are converted to doesn't even matter.

            // Let the array be [5, 11, 20, 20,], k = 5, numOperations = 3.

            // For j = 2, i would be 1 that means that both 11 and 20 could be converted to the same
            // number, possibly 15 or 16. That means it only matters how many elements could be
            // converted to a particular element not what element that particular element is.

            while (nums[i] + k < nums[j] - k) {
                i++;
            }
            maxFreq = max(maxFreq, min(j - i + 1, numOperations));
        }

        return maxFreq;
    }
};

int main() { return 0; }
