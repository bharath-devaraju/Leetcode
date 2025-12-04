// link -
// https://leetcode.com/problems/edit-distance/description/?envType=problem-list-v2&envId=dynamic-programming

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minDistance(string word1, string word2) {
        string& smallerWord = (word1.size() < word2.size()) ? word1 : word2;
        string& biggerWord = (word1.size() >= word2.size()) ? word1 : word2;

        return minDist(biggerWord, smallerWord, 0, 0);
    }

   private:
    int minDist(string& current, const string& target, int index1, int index2) {
        if (index1 >= current.size() || index2 >= target.size()) {
            return max(current.size() - index1, target.size() - index2);
        }

        if (current.at(index1) == target.at(index2))
            return minDist(current, target, index1 + 1, index2 + 1);

        string replace = current;
        replace[index1] = target[index2];

        int leastCost = 1 + minDist(replace, target, index1 + 1, index2 + 1);
        leastCost = min(leastCost, 1 + minDist(current, target, index1 + 1, index2));

        return leastCost;
    }
};

int main() { return 0; }
