#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int water = 0;
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m < 3 || n < 3) return 0;

        map<pair<int, int>, int> rowMap;
        map<pair<int, int>, int> colMap;

        const auto linearTrapping = [&](int r, int c, bool isRow) {
            int first = 0;
            int last = (isRow) ? n - 1 : m - 1;
            int maxFirst = 0, maxLast = 0;

            if (isRow) {
                while (first < last) {
                    if (heightMap[r][first] <= heightMap[r][last]) {
                        if (maxFirst < heightMap[r][first])
                            maxFirst = heightMap[r][first];
                        else {
                            rowMap[{r, first}] = maxFirst - heightMap[r][first];
                        }
                        first++;
                    } else {
                        if (maxLast < heightMap[r][last])
                            maxLast = heightMap[r][last];
                        else {
                            rowMap[{r, last}] = maxLast - heightMap[r][last];
                        }
                        last--;
                    }
                }
            }

            else {
                while (first < last) {
                    if (heightMap[first][c] <= heightMap[last][c]) {
                        if (maxFirst < heightMap[first][c])
                            maxFirst = heightMap[first][c];
                        else {
                            colMap[{first, c}] = maxFirst - heightMap[first][c];
                        }
                        first++;
                    } else {
                        if (maxLast < heightMap[last][c])
                            maxLast = heightMap[last][c];
                        else {
                            colMap[{last, c}] = maxLast - heightMap[last][c];
                        }
                        last--;
                    }
                }
            }
        };

        for (int i = 1; i < m - 1; i++) linearTrapping(i, 0, true);

        for (int i = 1; i < n - 1; i++) linearTrapping(0, i, false);

        for (auto [cell, potential] : rowMap) {
            if (colMap.count(cell)) {
                int potential2 = colMap[cell];
                water += min(potential, potential2);
            }
        }

        return water;
    }
};

int main() {
    Solution s1;
    vector<vector<int>> heightMap = {
        {3, 3, 3, 3, 3}, {3, 2, 2, 2, 3}, {3, 2, 1, 2, 3}, {3, 2, 2, 2, 3}, {3, 3, 3, 3, 3}};
    cout << s1.trapRainWater(heightMap);
    return 0;
}
