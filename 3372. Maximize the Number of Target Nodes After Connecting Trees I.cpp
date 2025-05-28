#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int DFS(vector<vector<int>> &graph, int limit, int curr, int parent = -1) {
        if (limit < 0)
            return 0;
        if (!limit)
            return 1;
        int reacheable = 1;
        for (int adj : graph[curr]) {
            if (adj == parent)
                continue;
            reacheable += DFS(graph, limit - 1, adj, curr);
        }
        return reacheable;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> graph1(n), graph2(m);
        for (auto edge : edges1) {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        for (auto edge : edges2) {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }

        int bestNode = 0;
        for (int i = 0; i < m; i++) 
            bestNode = max(bestNode, DFS(graph2, k - 1, i));
        
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = DFS(graph1, k, i) + bestNode;
        return ans;
    }
};

int main() {
    return 0;
}