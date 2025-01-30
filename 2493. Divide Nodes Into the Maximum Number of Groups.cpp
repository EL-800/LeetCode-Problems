#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> graph; 
    vector<int> colors;

    int BFS(int start) {
        int n = graph.size();        
        queue<int> pendingMoves;
        vector<int> visited(n);
        pendingMoves.push(start);
        visited[start] = 1;
        int maxDepth = 0;
        while (!pendingMoves.empty()) {
            int curr = pendingMoves.front();
            pendingMoves.pop();
            maxDepth = max(maxDepth, visited[curr]);
            for (int adj : graph[curr]) {
                if (visited[adj])
                    continue;
                visited[adj] = visited[curr] + 1;       
                pendingMoves.push(adj);         
            }
        }
        return maxDepth;
    }

    int Connected(int curr, int c = 0) {
        if (colors[curr] != -1)
            return 0;
        colors[curr] = c;
        int bestStart = BFS(curr);
        for (int adj : graph[curr]) {
            if (colors[adj] == c)
                return INT_MAX;
            else if (colors[adj] == -1)
                bestStart = max(bestStart, Connected(adj, 1 - c));        
        }
        return bestStart;
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        colors.assign(n, -1);
        graph.resize(n);
        for (auto edge : edges) {
            int node1 = edge[0] - 1, node2 = edge[1] - 1; 
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        int ans = 0;    
        for (int i = 0; i < n; i++) {
            if (colors[i] != -1)            
                continue;
            int maxConnected = Connected(i);
            if (maxConnected == INT_MAX)
                return -1;
            ans += maxConnected;
        }    
        return ans;
    }
};

int main() {
    return 0;
}