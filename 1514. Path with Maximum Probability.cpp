#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double, int>>> graph(n);
        for (int i = 0; i < (int)edges.size(); i++) {
            auto edge = edges[i];
            graph[edge[0]].push_back({ succProb[i], edge[1] });
            graph[edge[1]].push_back({ succProb[i], edge[0] });
        }
        priority_queue<pair<double, int>> nodes;
        nodes.push({ 1, start });
        vector<bool> vis(n);
        while (!nodes.empty()) {
            auto curr = nodes.top();
            nodes.pop();
            if (curr.second == end)
                return curr.first;
            if (vis[curr.second])
                continue;
            vis[curr.second] = true;            
            for (auto adj : graph[curr.second])
                nodes.push({ adj.first * curr.first, adj.second });
        }
        return 0;
    }
};

int main() {
    return 0;
}