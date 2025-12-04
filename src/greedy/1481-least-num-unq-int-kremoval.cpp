// link - https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
// Similar Questions
// src\greedy\1481-least-num-unq-int-kremoval.cpp

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> unqElements;
        for (int i : arr) {
            unqElements[i]++;
        }

        vector<int> countSort(n + 1, 0);

        for (auto [k, v] : unqElements) {
            countSort[v]++;
        }

        // The size is initialized to n because the maximum frequency of the number of n.

        int numRemaining = unqElements.size();
        for (int i = 1; i <= n; i++) {
            if (i > k) return numRemaining;

            int maxElementsRemoved = min(k / i, countSort[i]);

            k -= maxElementsRemoved * i;  // Removing the maximum number of elements of given freq.
            numRemaining -= maxElementsRemoved;
        }

        return 0;
    }

    /* int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> unqElements;

        for (int i : arr) {
            unqElements[i]++;
        }

        const auto sortFunc = [&](int i, int j) { return unqElements[j] < unqElements[i]; };

        priority_queue<int, vector<int>, greater<int>> heap(sortFunc);

        for (auto [k, v] : unqElements) heap.push(k);

        while (k > 0 && !heap.empty()) {
            int top = heap.top();

            if (k < unqElements[top]) return heap.size();

            k -= unqElements[top];
            heap.pop();
        }

        return heap.size();
    } */
};

int main() { return 0; }
