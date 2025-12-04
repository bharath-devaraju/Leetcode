#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dpTable(m, vector<int>(n, vector<int>(k, 0)));

        const auto updateRems = [&](int r, int c, array<int, 2> dir) -> void {
            if (r + dir[0] >= m || c + dir[1] >= n) return;

            for (int rem = 0; rem < k; rem++) {
                int pos = (grid[r][c] + rem) % k;
                dpTable[r][c][pos] += dpTable[r + dir[0]][c + dir[1]][rem];
            }
        };

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if ((i == m - 1) && (j == n - 1)) {
                    dpTable[i][j][grid[i][j] % k] += 1;
                    continue;
                }

                updateRems(i, j, {0, 1});
                updateRems(i, j, {1, 0});
            }
        }

        return dpTable[0][0][0];
    }
};

int main() { return 0; }
