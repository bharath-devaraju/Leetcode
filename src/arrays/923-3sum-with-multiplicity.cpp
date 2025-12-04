#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1e9 + 7;
        const int maxVal = 100;
        array<long, maxVal + 1> freqMap = {0};
        int total = 0;

        const auto numTuples = [&](int i, int j, int k) -> int {
            if (i == j && j == k)
                return (((freqMap[i]) * (freqMap[i] - 1) * (freqMap[i] - 2)) / 6) % MOD;

            if (i == j) return (((freqMap[i]) * (freqMap[i] - 1)) / 2 * freqMap[k]) % MOD;

            if (i == k) return (((freqMap[i]) * (freqMap[i] - 1)) / 2 * freqMap[j]) % MOD;

            if (j == k) return (((freqMap[j]) * (freqMap[j] - 1)) / 2 * freqMap[i]) % MOD;

            return (freqMap[i] * freqMap[j] * freqMap[k]) % MOD;
        };

        for (int i = 0; i <= maxVal; i++) {
            if (freqMap[i]) {
                for (int j = i; j <= maxVal; j++) {
                    int k = target - i - j;
                    if (k < i) break;

                    if (k <= 100 && freqMap[j] && freqMap[k]) total += numTuples(i, j, k);
                }
            }
        }

        return total;
    }
    /* int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1000000007;
        const int maxVal = 100;
        int total = 0;
        array<long, maxVal + 1> freqMap = {0};

        for (int i : arr) {
            freqMap[i]++;
        }

        const auto numTuples = [&](int i, int j, int k) -> int {
            if (i == j && j == k)
                return (((freqMap[i]) * (freqMap[i] - 1) * (freqMap[i] - 2)) / 6) % MOD;

            if (i == j) return (((freqMap[i]) * (freqMap[i] - 1)) / 2 * freqMap[k]) % MOD;

            if (i == k) return (((freqMap[i]) * (freqMap[i] - 1)) / 2 * freqMap[j]) % MOD;

            if (j == k) return (((freqMap[j]) * (freqMap[j] - 1)) / 2 * freqMap[i]) % MOD;

            return (freqMap[i] * freqMap[j] * freqMap[k]) % MOD;
        };

        const auto findPair = [&](int tar, int index) {
            int totalPairs = 0;
            for (int i = index; i <= maxVal; i++) {
                int diff = tar - i;

                if (diff < i) break;

                if (diff <= 100 && freqMap[i] && freqMap[diff])
                    totalPairs += numTuples(index, i, diff);
            }

            return totalPairs;
        };

        for (int i = 0; i <= maxVal; i++) {
            if (freqMap[i]) {
                total += findPair(target - freqMap[i], i) % MOD;
            }
        }

        return total;
    } */
};
int main() { return 0; }
