#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> visits(n + 1), dists(n + 1, -1);
        vector<vector<int>> graph(n + 1);        
        queue<pair<int, int>> pendingMoves;
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        pendingMoves.push({1, 0});
        while (!pendingMoves.empty()) {
            auto [node, dist] = pendingMoves.front();
            pendingMoves.pop();
            if (dists[node] == dist || visits[node] == 2)
                continue;
            dists[node] = dist;
            visits[node]++;
            for (auto adj : graph[node])
                pendingMoves.push({adj, dist + 1});            
        }
        int ans=0;
        for(int i=0; i < dists[n]; i++) {
            int gr=ans/change;
            if (gr&1)
                ans=(gr+ 1)*change;
            ans+=time;
        }
        return ans;        
    }
};

int main() {
    return 0;
}