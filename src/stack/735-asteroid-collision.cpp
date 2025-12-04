// link https://leetcode.com/problems/asteroid-collision/
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> roidStack;
        roidStack.reserve(asteroids.size());

        for (int i : asteroids) {
            bool destroyed = false;

            while (!roidStack.empty() && (i < 0 && roidStack.back() > 0)) {
                if (-i <= roidStack.back()) {
                    if (-i == roidStack.back()) roidStack.pop_back();
                    destroyed = true;
                    break;
                }

                roidStack.pop_back();
            }

            if (!destroyed) roidStack.emplace_back(i);
        }

        return roidStack;
    }
};

int main() { return 0; }
