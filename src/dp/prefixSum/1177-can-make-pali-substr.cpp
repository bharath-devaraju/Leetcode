// link : https://leetcode.com/problems/can-make-palindrome-from-substring/description/
// Similar
// src\dp\prefixSum\2055-plates-between-candles.cpp

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int numQueries = queries.size();
        int slen = s.size();
        vector<bool> result(numQueries, false);

        // Prefix array of the string that gives the number of odd freq chars upto an index.
        vector<int> oddFreq(slen + 1);

        for (int i = 0; i < slen; i++) {
            // Xor gives whether the current character frequency is odd or even until now.
            oddFreq[i + 1] = oddFreq[i] ^ (1 << s[i] - 'a');
        }

        for (int q = 0; q < numQueries; q++) {
            int l = queries[q][0];
            int u = queries[q][1];
            int k = queries[q][2];

            // Counting the number of odd frequncy characters within the given range.
            int numOdds = __builtin_popcount((oddFreq[u + 1] ^ oddFreq[l]));
            result[q] = (numOdds >> 1) <= k;
        }

        return result;
    }

    /* vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) { */
    /*     int querySize = queries.size(); */
    /*     int slen = s.size(); */
    /**/
    /*     vector<bool> result(querySize, false); */
    /*     vector<array<int, 26>> prefixMap(slen, {0}); */
    /**/
    /*     array<int, 26> freqMap = {0}; */
    /**/
    /*     for (int c = 0; c < slen; c++) { */
    /*         freqMap[s[c] - 'a']++; */
    /*         copy(freqMap.begin(), freqMap.end(), prefixMap[c].begin()); */
    /*     } */
    /**/
    /*     for (int q = 0; q < querySize; q++) { */
    /*         int ll = queries[q][0]; */
    /*         int ul = queries[q][1]; */
    /*         int k = queries[q][2]; */
    /**/
    /*         array<int, 26> temp = {0}; */
    /**/
    /*         for (int i = 0; i < 26; i++) { */
    /*             temp[i] = prefixMap[ul][i] - prefixMap[ll][i]; */
    /*         } */
    /**/
    /*         temp[s[ll] - 'a']++; */
    /**/
    /*         result[q] = canTransformPali(temp, k, (ul - ll + 1) % 2); */
    /*     } */
    /**/
    /*     return result; */
    /* } */

    /* private:
     bool canTransformPali(array<int, 26>& freqMap, int k, bool canOddExist) {
         int numOdds = -canOddExist;

         for (int i : freqMap) {
             numOdds += (i % 2);
         }

         return (numOdds % 2) ? false : ((numOdds >> 1) <= k);
     } */
};

int main(int argc, char** argv) {
    vector<vector<int>> queries = {{3, 3, 0}, {1, 2, 0}, {0, 3, 1}, {0, 3, 2}, {0, 4, 1}};
    Solution s1;
    s1.canMakePaliQueries("abcda", queries);
    return 0;
}
