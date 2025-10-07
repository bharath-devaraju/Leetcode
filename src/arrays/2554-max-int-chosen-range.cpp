#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int result = 0;
        vector<int> nums(n, 0);

        iota(nums.begin(), nums.end(), 1);

        for (size_t i = 0; i < banned.size(); i++) {
            if (banned[i] >= 1 && banned[i] <= n) nums[banned[i] - 1] = 0;
        }

        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (maxSum - nums[i]) {
                    result++;
                    maxSum - nums[i];
                } else
                    return result;
            }
        }

        return result;
    }
};
int main() {
    int size, n, maxSum;
    cin >> size;
    vector<int> banned(size, 0);

    for (int i = 0; i < size; i++) {
        cin >> banned[i];
    }

    cin >> n;
    cin >> maxSum;

    Solution s1;
    cout << s1.maxCount(banned, n, maxSum);

    return 0;
}
