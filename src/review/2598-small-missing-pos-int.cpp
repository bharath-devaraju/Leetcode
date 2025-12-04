// link :
// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/
//

// Concept MEX : Minimum Exceeding value is the smallest missing non negative int in the array.
//  MEX value cannot be more than the length of the array.

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int> bucket(value, 0);

        for (int& i : nums) {
            int rem = (i % value + value) % value;  // Reminder for both positive and negative
            bucket[rem]++;                          // Populating the buckets with reminders.
        }

        int mex = 0;  // Initially Mex would be zero, It cannot exceed n.

        for (; mex <= n; mex++) {
            // Checking if there are still elements in the bucket.
            int rem = mex % value;

            if (bucket[rem] ==
                0)  // The bucket is exhausted, meaning currnet number(MEX) cannot be formed.
                return mex;

            bucket[rem]--;
        }

        return n;  // Cannot exceed n
    }

    /* int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        map<int, int> freqMap;
        set<int> notPresent;

        for (int i = 0; i < n; i++) {
            notPresent.insert(i);
            freqMap[nums[i]]++;
        }

        for (const auto [k, v] : freqMap) {
            if (notPresent.count(k)) notPresent.erase(k);
        }

        for (int i = 0; i < n; i++) {
            if (!notPresent.size()) return n;

            int mex = *notPresent.begin();

            if (abs((nums[i] - mex)) % value == 0) {
                if (nums[i] < 0 || nums[i] > mex) {
                    notPresent.erase(mex);
                    freqMap[mex]++;
                    if (nums[i] >= 0 && --freqMap[nums[i]] <= 0) notPresent.insert(nums[i]);
                }
            }

            // cout << notPresent.size() << endl;
        }
        return *notPresent.begin();
    } */
};

int main() {
    vector<int> nums = {3, 2, 3, 1, 0, 1, 4, 2, 3, 1, 4, 1, 3};
    int value = 5;

    Solution s1;
    cout << s1.findSmallestInteger(nums, value);
    return 0;
}
