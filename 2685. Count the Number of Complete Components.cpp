#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        vector<vector<int>> graph;
        vector<bool> visited;

        pair<int, int> CheckComponent(int curr) {
            if (visited[curr])
                return {0, 0};
            visited[curr] = true;
            int vertices = 0, edges = 0;
            for (auto adj : graph[curr]) {
                auto [adjV, adjE] = CheckComponent(adj);
                vertices += adjV;
                edges += adjE + 1;
            }
            return {vertices + 1, edges};
        }

    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            graph.resize(n);
            visited.resize(n);
            for (auto edge : edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (visited[i])
                    continue;
                auto [vertices, edges] = CheckComponent(i);
                ans += vertices * (vertices - 1) == edges;
            }
            return ans;
        }
    };

int main() {
    return 0;
}