// link -
// https://leetcode.com/problems/power-grid-maintenance/

#include <bits/stdc++.h>

using namespace std;
class Solution {
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        vector<int> res;
        vector<int> status(c + 1, 1);
        map<int, vector<int>> grid;

        vector<int> parents(c + 1, 0);
        iota(parents.begin(), parents.end(), 0);

        for (vector<int>& connection : connections) {
            int u = connection[0];
            int v = connection[1];

            grid[u].emplace_back(v);
            grid[v].emplace_back(u);
        }

        dfs(c, grid, parents);

        for (vector<int>& query : queries) {
            int operation = query[0];
            int node = query[1];

            if (operation == 2) {
                status[node] = -1;
                int root = parents[node];
                if (connectedComponents.contains(root)) connectedComponents[root].erase(node);

            } else {
                int nearest = -1;
                if (status[node] == 1)
                    nearest = node;
                else {
                    int root = parents[node];

                    if (connectedComponents.contains(root) && connectedComponents[root].size()) {
                        nearest = *(connectedComponents[root].begin());
                    }
                }

                res.emplace_back(nearest);
            }
        }
        return res;
    }

   private:
    map<int, set<int>> connectedComponents;
    void dfs(int c, map<int, vector<int>>& adjList, vector<int>& parents) {
        vector<bool> visited(c + 1, false);
        for (int i = 1; i <= c; i++) {
            if (!visited[i]) {
                set<int> component;
                component.insert(i);
                dfsHelper(i, visited, adjList, i, parents);
            }
        }
    }

    void dfsHelper(int current, vector<bool>& visited, map<int, vector<int>>& adjList, int parent,
                   vector<int>& parents) {
        visited[current] = true;
        connectedComponents[parent].insert(current);
        parents[current] = parent;

        for (int node : adjList[current]) {
            if (!visited[node]) {
                dfsHelper(node, visited, adjList, parent, parents);
            }
        }
    }

    /* vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        int qSize = queries.size();
        vector<int> res;
        vector<int> status(c, 1);
        map<int, vector<int>> grid;

        for (const auto& stationPair : connections) {
            int u = stationPair[0];
            int v = stationPair[1];

            grid[u].emplace_back(v);
            grid[v].emplace_back(u);
        }

        const auto checkNearestOnline = [&](int station) -> int {
            if (status[station - 1] == 1)
                return station;

            queue<int> bfsQueue;
            vector<bool> visited(c, false);

            bfsQueue.push(station);
            visited[station - 1] = true;
            int nearest = c + 1;

            while (!bfsQueue.empty()) {
                int currentStation = bfsQueue.front();
                bfsQueue.pop();

                if (status[currentStation - 1] == 1) {
                    nearest = min(nearest, currentStation);
                }

                for (int node : grid[currentStation]) {
                    if (!visited[node - 1]) {
                        bfsQueue.push(node);
                        visited[node - 1] = true;
                    }
                }
            }

            return nearest <= c ? nearest : -1;
        };

        for (vector<int> &q : queries) {
            int operation = q[0];
            int station = q[1];

            if (operation == 2)
                status[station - 1] = -1;

            else {
                int maintenanceStatus = checkNearestOnline(station);
                res.emplace_back(maintenanceStatus);
            }
        }

        return res;
    } */
};

int main() { return 0; }
