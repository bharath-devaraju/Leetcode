// link -
// https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/?envType=daily-question&envId=2025-11-10

class Solution {
   public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int numOperations = 0;
        stack<int> monoStack;

        for (int i : nums) {
            if (i == 0) {
                monoStack = stack<int>();
                continue;
            }

            while (!monoStack.empty() && monoStack.top() > i) {
                monoStack.pop();
            }

            if (monoStack.empty() || monoStack.top() < i) {
                monoStack.push(i);
                numOperations++;
            }
        }

        return numOperations;
    }
};
