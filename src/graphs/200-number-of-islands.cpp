// link - https://leetcode.com/problems/number-of-islands/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return dfsHelper(grid, visited);
    }

   private:
    int dfsHelper(vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int islandCount = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, visited);
                    islandCount++;
                }
            }
        }

        return islandCount;
    }

    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        for (auto& dir : dirs) {
            int x = row + dir[0];
            int y = col + dir[1];

            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visited[x][y])
                continue;

            if (grid[x][y] == '1') dfs(x, y, grid, visited);
        }
    }
};

int main() { return 0; }
