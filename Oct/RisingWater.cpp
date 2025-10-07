#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int minTime = 0;
        int maxTime = n * n - 1;

        const auto traverse = [&](int time) {
            queue<pair<int, int>> bfs_queue;
            bfs_queue.push({0, 0});
            bfs_queue.push({n - 1, n - 1});
            unordered_map<int, int> visited;

            visited[grid[0][0]] = 0;
            visited[grid[n - 1][n - 1]] = n * n - 1;

            while (!bfs_queue.empty()) {
                auto [r, c] = bfs_queue.front();
                bfs_queue.pop();
                for (int i = 0; i < 4; i++) {
                    int x = r + dir[i][0];
                    int y = c + dir[i][1];

                    if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] <= time) {
                        if (visited.count(grid[x][y])) {
                            if (visited[grid[x][y]] != visited[grid[r][c]]) return true;
                            continue;
                        }

                        bfs_queue.push({x, y});
                        visited[grid[x][y]] = visited[grid[r][c]];
                    }
                }
            }

            return false;
        };

        while (minTime < maxTime) {
            int time = minTime + (maxTime - minTime) / 2;
            if (grid[0][0] <= time && grid[n - 1][n - 1] <= time && traverse(time))
                maxTime = time;
            else
                minTime = time + 1;
        }

        return minTime;
    }
};

int main() {
    Solution s1;
    vector<vector<int>> heightMap = {{0, 2}, {1, 3}};
    cout << s1.swimInWater(heightMap);
    return 0;
}
