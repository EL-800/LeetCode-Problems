#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int SearchReacheable(vector<vector<pair<int, int>>>& graph, int distanceThreshold, int initialNode) {
        vector<bool> visited(graph.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pendingMoves;        
        int reacheables = 0;        
        pendingMoves.push({0, initialNode});        
        while (!pendingMoves.empty()) {
            auto [dist, node] = pendingMoves.top();
            pendingMoves.pop();
            if (dist > distanceThreshold)
                continue;
            if (visited[node])
                continue;
            visited[node] = true;
            reacheables++;
            for (auto [adjNode, adjDist] : graph[node]) 
                pendingMoves.push({adjDist + dist, adjNode});            
        }
        return reacheables;
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        int minReacheable = INT_MAX, minNode = -1;
        for (int i = 0; i < n; i++) {
            int reacheables = SearchReacheable(graph, distanceThreshold, i);
            if (reacheables <= minReacheable) {
                minNode = i;
                minReacheable = reacheables;
            }
        }
        return minNode;
    }
};

int main() {
    return 0;
}