// link - https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minDeletions(string s) {
        int numDeleted = 0;
        array<int, 26> charCount;

        for (char c : s) charCount[c - 'a']++;

        sort(charCount.begin(), charCount.begin() + 26, greater<int>());
        unordered_set<int> visited;

        for (int i = 0; i < 26; i++) {
            while (visited.count(charCount[i])) {
                charCount[i]--;
                numDeleted++;
            }
            visited.insert(charCount[i]);
        }

        return numDeleted;
    }
};

int main() { return 0; }
