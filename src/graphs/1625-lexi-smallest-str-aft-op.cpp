// link -
// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/?envType=daily-question&envId=2025-10-19

class Solution {
   public:
    string findLexSmallestString(string s, int a, int b) {
        int size = s.size();

        queue<string> bfsQueue;
        set<string> visited;

        bfsQueue.push(s);
        visited.insert(s);

        while (!bfsQueue.empty()) {
            string top = bfsQueue.front();
            bfsQueue.pop();

            string UpdateOddString = top;
            string rotateString = top;

            for (int i = 1; i < size; i += 2) {
                int c = (UpdateOddString[i] - '0' + a) % 10;
                UpdateOddString[i] = '0' + c;
            }

            reverse(rotateString.begin(), rotateString.begin() + b);
            reverse(rotateString.begin() + b, rotateString.end());
            reverse(rotateString.begin(), rotateString.end());

            if (!visited.count(UpdateOddString)) {
                bfsQueue.push(UpdateOddString);
                visited.insert(UpdateOddString);
            }

            if (!visited.count(rotateString)) {
                bfsQueue.push(rotateString);
                visited.insert(rotateString);
            }
        }

        return *visited.begin();
    }
};
