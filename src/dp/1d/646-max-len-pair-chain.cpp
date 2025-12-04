// link :
// https://leetcode.com/problems/maximum-length-of-pair-chain/?envType=problem-list-v2&envId=x1k8lxi5

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs));
        int n = pairs.size();
        int maxLen = 0;
        vector<int> maxChain(n, 1);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (pairs[i][0] < pairs[j][0]) maxChain[i] = max(maxChain[i], maxChain[j] + 1);
            }

            maxLen = max(maxLen, maxChain[i]);
        }

        return maxLen;
    }
};

int main() { return 0; }
