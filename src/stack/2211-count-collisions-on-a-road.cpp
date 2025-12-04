// link -
// https://leetcode.com/problems/count-collisions-on-a-road/?envType=daily-question&envId=2025-12-04
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int countCollisions(string directions) {
        int n = directions.size();
        int l = 0, r = n - 1;

        while (l < n && directions[l] == 'L') {
            l++;
        }

        while (r >= l && directions[r] == 'R') {
            r--;
        }

        int res = 0;
        for (int i = l; i <= r; i++) {
            if (directions[i] != 'S') {
                res++;
            }
        }
        return res;
    }
    int countCollisions(string directions) {
        int collisions = 0;
        int numRights = 0;
        bool stationary = false;

        for (const char& c : directions) {
            if (c == 'R')
                numRights++;

            else {
                if (numRights || c == 'S') {
                    collisions += numRights + (c == 'L');
                    stationary = true;
                    numRights = 0;
                }

                else if (c == 'L' && stationary)
                    collisions++;
            }
        }

        return collisions;
    }

    int countCollisions(string directions) {
        // if curr = L then the first R collision will create S that when combined will combine with
        // other R's before it. if curr = R then any L's before it won't matter

        // For S every L coming after it will collide and increases collisions by 1.
        // For S every R combing before it will collide and increase collisions by 1.

        int collisions = 0;
        stack<char> carStack;

        for (const char& c : directions) {
            char current = c;
            if (current == 'L' && carStack.empty()) continue;

            while (!carStack.empty()) {
                if (current == 'S' && carStack.top() == 'R') {
                    collisions += 1;
                    carStack.pop();
                }

                else if (current == 'L') {
                    if (carStack.top() == 'R') collisions += 2;
                    if (carStack.top() == 'S') collisions += 1;

                    current = 'S';
                    carStack.pop();
                }

                else {
                    break;
                }
            }

            carStack.push(current);
        }

        return collisions;
    }
};

int main() { return 0; }
