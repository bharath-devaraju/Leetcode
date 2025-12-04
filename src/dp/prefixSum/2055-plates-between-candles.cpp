// link : https://leetcode.com/problems/plates-between-candles/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int tableLen = s.size();
        int querySize = queries.size();
        vector<int> result(querySize, 0);

        vector<pair<int, int>> nearestCandle(tableLen, {0, 0});
        vector<int> numPlates(tableLen + 1, 0);

        int leftMostCandle = -1;
        int rightMostCandle = -1;

        for (int i = 0, j = tableLen - 1; i < tableLen && j >= 0; i++, j--) {
            if (s[i] == '|') leftMostCandle = i;
            if (s[j] == '|') rightMostCandle = j;

            nearestCandle[i].first = {leftMostCandle};
            nearestCandle[j].second = {rightMostCandle};

            numPlates[i + 1] = (s[i] == '*') ? 1 + numPlates[i] : numPlates[i];
        }

        for (int q = 0; q < queries.size(); q++) {
            int l = queries[q][0];
            int r = queries[q][1];

            int firstCandle = nearestCandle[l].second;
            int lastCandle = nearestCandle[r].first;

            if (firstCandle != -1 && lastCandle != -1 && firstCandle <= r && lastCandle >= l) {
                result[q] = numPlates[lastCandle] - numPlates[firstCandle];
            }
        }

        return result;
    }
};

int main() { return 0; }
