// link : https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> answer(n, -1);
        answer[0] = 0;

        const auto comparator = [&](int i, int j) { return answer[i] < answer[j]; };
        priority_queue<int, vector<int>, decltype(comparator)> nodes(comparator);
        set<int> visited;
        vector<vector<int>> adjList(n, vector<int>(n, INT_MAX));
        nodes.push(0);
        visited.insert(0);

        for (const auto edge : edges) {
            adjList[edge[0]][edge[1]] = edge[2];
        }

        while (nodes.empty()) {
            int top = nodes.top();
            nodes.pop();

            for (int i : edges[top]) {
                if (i != INT_MAX && !visited.count(i)) {
                    answer[i] = min(answer[i], answer[top] + adjList[top][i]);
                    nodes.push(i);
                    visited.insert(i);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            answer[i] = (answer[i] <= disappear[i]) ? answer[i] : -1;
        }

        return answer;
    }
};

int main() { return 0; }
