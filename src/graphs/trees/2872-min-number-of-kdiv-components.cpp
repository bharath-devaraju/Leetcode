// link -
// https://leetcode.com/problems/maximum-number-of-k-divisible-components/submissions/1841708092/?envType=daily-question&envId=2025-11-28
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // Base case: if there are less than 2 nodes, return 1
        if (n < 2) return 1;

        int componentCount = 0;
        unordered_map<int, unordered_set<int>> graph;

        // Step 1: Build the graph
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            graph[node1].insert(node2);
            graph[node2].insert(node1);
        }

        // Convert values to long long to prevent overflow
        vector<long long> longValues(values.begin(), values.end());

        // Step 2: Initialize the BFS queue with leaf nodes (nodes with only one
        // connection)
        queue<int> queue;
        for (const auto& [node, neighbors] : graph) {
            if (neighbors.size() == 1) {
                queue.push(node);
            }
        }

        // Step 3: Process nodes in BFS order
        while (!queue.empty()) {
            int currentNode = queue.front();
            queue.pop();

            // Find the neighbor node
            int neighborNode = -1;
            if (!graph[currentNode].empty()) {
                neighborNode = *graph[currentNode].begin();
            }

            if (neighborNode >= 0) {
                // Remove the edge between current and neighbor
                graph[neighborNode].erase(currentNode);
                graph[currentNode].erase(neighborNode);
            }

            // Check divisibility of the current node's value
            if (longValues[currentNode] % k == 0) {
                componentCount++;
            } else if (neighborNode >= 0) {
                // Add current node's value to the neighbor
                longValues[neighborNode] += longValues[currentNode];
            }

            // If the neighbor becomes a leaf node, add it to the queue
            if (neighborNode >= 0 && graph[neighborNode].size() == 1) {
                queue.push(neighborNode);
            }
        }

        return componentCount;
    }

    // Using DFS
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        map<int, vector<int>> adjList;
        vector<int> parents(n, 0);

        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> visited(n, false);
        dfs(0, adjList, values, visited, k);
        return totalDivisableComponents;
    }

   private:
    int totalDivisableComponents = 1;
    int dfs(int current, map<int, vector<int>>& edges, vector<int>& values, vector<bool>& visited,
            int k) {
        visited[current] = true;
        int currentTreeSum = values[current];
        for (int neighbor : edges[current]) {
            if (!visited[neighbor]) {
                int subTreeSum = dfs(neighbor, edges, values, visited, k);
                if (subTreeSum % k == 0)
                    totalDivisableComponents++;
                else {
                    currentTreeSum = (currentTreeSum + subTreeSum) % k;
                }
            }
        }

        return currentTreeSum;
    }
};

int main() { return 0; }
