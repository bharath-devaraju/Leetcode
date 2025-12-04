// link -
// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/editorial/?envType=daily-question&envId=2025-11-08

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;
        return numOperations(n);
    }

   private:
    int numOperations(int n) {
        if (n == 0) return 0;

        int pos = 31 - __builtin_clz(n);
        int msb = 1 << pos;

        return ((1 << (pos + 1)) - 1) - numOperations(n ^ msb);
    }
};

int main() { return 0; }
