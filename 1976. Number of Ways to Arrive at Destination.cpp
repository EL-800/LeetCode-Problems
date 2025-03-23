#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            vector<vector<pair<int, int>>> graph(n);
            for (auto road : roads) {
                int u = road[0], v = road[1], w = road[2];
                graph[u].push_back({v, w});
                graph[v].push_back({u, w});
            }
            const int mod = 1e9 + 7;
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pendingMoves;
            vector<long long> dist(n, LLONG_MAX), memo(n);
            pendingMoves.push({0, 0});
            dist[0] = 0;
            memo[0] = 1;
            while (!pendingMoves.empty()) {
                auto [currDis, currNode] = pendingMoves.top();
                pendingMoves.pop();
                if (dist[currNode] < currDis)
                    continue;
                for (auto [adjNode, adjDis] : graph[currNode]) {
                    if (dist[adjNode] > adjDis + currDis) {
                        dist[adjNode] = adjDis + currDis;
                        memo[adjNode] = memo[currNode];
                        pendingMoves.push({adjDis + currDis, adjNode});
                    }                    
                    else if (dist[adjNode] == adjDis + currDis)
                        memo[adjNode] = (memo[adjNode] + memo[currNode]) % mod;                    
                }
            }
            return memo[n - 1];
        }
    };

int main() {
    return 0;
}