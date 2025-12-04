#include <bits/stdc++.h>

using namespace std;
// link -

class Solution {
   public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // sort according to upperLimit of the intervals
        sort(begin(intervals), end(intervals), [&](vector<int>& i, vector<int>& j) {
            if (i[1] != j[1]) return i[1] < j[1];

            return (i[1] - i[0] < j[1] - j[0]);
        });

        int maxRight = -1;
        int nextMaxRight = -1;
        int minSetSize = 0;

        for (vector<int>& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            if (maxRight < start) {
                maxRight = end;
                nextMaxRight = end - 1;
                minSetSize += 2;
            }

            // if maxright is greater but nextMax is lesser that means only one new element is to be
            // chosen.

            else if ((maxRight >= start) && (nextMaxRight < start)) {
                nextMaxRight = maxRight;
                maxRight = end;
                minSetSize += 1;
            }
        }

        return minSetSize;
    }
};

int main() { return 0; }
