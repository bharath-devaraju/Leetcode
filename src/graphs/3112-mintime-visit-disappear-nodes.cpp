// link : https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> adjList(n);
        vector<int> answer(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> nextNode;

        for (const auto edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        answer[0] = 0;
        nextNode.push({0, 0});

        while (!nextNode.empty()) {
            auto [dist, curr] = nextNode.top();
            nextNode.pop();

            if (dist > answer[curr]) continue;

            for (const auto [v, w] : adjList[curr]) {
                int newDist = dist + w;
                if (newDist < disappear[v]) {
                    if (answer[v] <= newDist && answer[v] != -1) continue;
                    answer[v] = newDist;
                    nextNode.push({answer[v], v});
                }
            }
        }

        return answer;
    }
};
int main() {
    int n = 3;
    vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 1}, {0, 2, 4}};
    vector<int> disappear = {1, 3, 5};

    Solution s1;
    vector<int> result = s1.minimumTime(n, edges, disappear);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
