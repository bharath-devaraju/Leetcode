#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> atlanticPacific(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result;

        queue<pair<int, int>> atlanticQueue;
        queue<pair<int, int>> pacificQueue;
        set<pair<int, int>> atlanticReachable;
        set<pair<int, int>> pacificReachable;

        for (int i = 0; i < m; i++) {
            pacificQueue.push({i, 0});
            pacificReachable.insert({i, 0});
            atlanticQueue.push({i, n - 1});
            atlanticReachable.insert({i, n - 1});
        }

        for (int i = 0; i < n; i++) {
            pacificQueue.push({0, i});
            pacificReachable.insert({0, i});
            atlanticQueue.push({m - 1, i});
            atlanticReachable.insert({m - 1, i});
        }

        const auto bfs = [&](bool atlantic) {
            queue<pair<int, int>>& que = (atlantic) ? (atlanticQueue) : (pacificQueue);
            set<pair<int, int>>& reachable = (atlantic) ? (atlanticReachable) : (pacificReachable);

            while (!que.empty()) {
                auto [r, c] = que.front();
                que.pop();

                for (int i = 0; i < 4; i++) {
                    int x = r + dir[i][0];
                    int y = c + dir[i][1];

                    if (x >= 0 && y >= 0 && x < m - 1 && y < n - 1 && !reachable.count({x, y}) &&
                        heights[x][y] >= heights[r][c]) {
                        que.push({x, y});
                        reachable.insert({x, y});
                    }
                }
            }
        };

        bfs(true);
        bfs(false);

        for (const auto elem : atlanticReachable) {
            if (pacificReachable.count(elem))
                result.push_back(vector<int>({elem.first, elem.second}));
        }

        return result;
    }
};

int main() {
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};

    Solution s1;
    const auto result = s1.atlanticPacific(heights);

    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
