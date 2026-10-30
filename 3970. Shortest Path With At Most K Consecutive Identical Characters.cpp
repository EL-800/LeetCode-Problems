#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<int>> visited(n, vector<int>(k + 1, INT_MAX));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pendingMoves;
        vector<vector<pair<int, int>>> graph(n);

        if (n == 1)
            return 0;

        for (auto &edge : edges) 
            graph[edge[0]].push_back({edge[1], edge[2]});        

        pendingMoves.push({0, 0, 1});
        while (!pendingMoves.empty()) {
            auto [weight, node, consecutive] = pendingMoves.top();
            pendingMoves.pop();

            if (node == n - 1)
                return visited[node][consecutive];

            for (auto &[adjN, adjW] : graph[node]) {
                int totalW = weight + adjW;
                int adjC = labels[node] == labels[adjN] ? consecutive + 1 : 1;

                if (adjC > k)
                    continue;
                if (totalW  >= visited[adjN][adjC])
                    continue;
                
                visited[adjN][adjC] = totalW;
                pendingMoves.push({totalW, adjN, adjC});
            }
        }

        return -1;
    }
};

int main() {
    return 0;
}