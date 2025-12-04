// link :
// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/?envType=daily-question&envId=2025-10-15

// Similar questions
// C:\Users\bhara\OneDrive\Desktop\Seek\DSA\LC\src\arrays\3349-has-inc-subarr.cpp

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int currLen = 0, prevLen = 0;
        int maxLen = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] > 0)
                currLen++;
            else {
                prevLen = currLen;
                currLen = 1;
            }

            if (currLen > prevLen)
                // If the current length is greater check if the current subarray be divided into
                // two equal halves greater than the previous subArray.
                maxLen = max(maxLen, max(prevLen, currLen / 2));
            else
                // Considering the previous SubArray how big can the current subArray be.
                // For e.g if prev = 5 and curr = 3 that means we can at least have consecutive
                // subArrays of length 3.
                maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }

    /* int maxIncreasingSubarrays(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> startingAtIndex(n, 1);
        vector<int> endingAtIndex(n, 1);
        int maxK = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > 0) {
                endingAtIndex[i] = 1 + endingAtIndex[i - 1];
            }

            if (nums[n - i] - nums[n - i - 1] > 0) {
                startingAtIndex[n - i - 1] = 1 + startingAtIndex[n - i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (i) {
                maxK = max(maxK, min(endingAtIndex[i - 1], startingAtIndex[i]));
            }
        }

        return maxK;
    } */

    /* int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> startingAtIndex(n, 1);

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] - nums[i] > 0) {
                startingAtIndex[i] = 1 + startingAtIndex[i + 1];
            }
        }

        const auto adjSubArrayPossible = [&](int k) {
            for (int i = 0; i < n - k - 1; i++) {
                if (startingAtIndex[i] >= k && startingAtIndex[i + k] >= k) {
                    return true;
                }
            }

            return false;
        };

        int minK = 0;
        int maxK = n / 2;

        while (minK <= maxK) {
            int midK = minK + (maxK - minK) / 2;

            if (adjSubArrayPossible(midK))
                minK = midK + 1;
            else
                maxK = midK - 1;
        }

        return minK - 1;
    } */
};

int main() {
    vector<int> nums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};

    Solution s1;
    cout << s1.maxIncreasingSubarrays(nums);
    return 0;
}
