// link - https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/
// Read Editorial

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    // Advanced Sliding window with ever increasing window size.

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        long runningSum = 0;

        for (int right = 0; right < nums.size(); right++) {
            runningSum += nums[right];
            long target = nums[right];

            // window shrinkage not necessary because we only search for larger windows than
            // current.
            if ((right - left + 1) * target - runningSum > k) {
                runningSum -= nums[left];
                left++;
            }
        }

        return nums.size() - left;
    }

    // Sliding Window with Shrinking Window size

    /* int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int runningSum = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            runningSum += nums[right];
            int target = nums[right];

            while ((right - left + 1) * target - runningSum > k) {
                runningSum -= nums[left];
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    } */

    // Self Approach

    /* int maxFrequency(vector<int>& nums, int k) {
        int maxFreq = 0;
        map<int, int> freqMap;

        for (int i : nums) freqMap[i]++;

        for (int i = 0; i < freqMap.size(); i++){
            auto it = freqMap.begin();
            advance(it, i);

            int cost = k;
            int totalFreq = 0;

            for (int j = i - 1; j >= 0; j--){
                auto jt = freqMap.begin();
                advance(jt, j);

                int diff = it->first - jt->first;
                int maxChange = cost / diff;
                int change = min(jt->second, maxChange);

                if (maxChange == 0)
                    break;

                cost -= change * diff;
                totalFreq += change;
            }

            totalFreq += it->second;
            maxFreq = max(maxFreq, totalFreq);
        }

        return maxFreq;
    } */
};

int main() { return 0; }
