#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> adjList;
public:
    Graph(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        for (vector<int> edge : edges)
            adjList[edge[0]].push_back({edge[2], edge[1]});
    }
    
    void addEdge(vector<int> edge) {
        adjList[edge[0]].push_back({edge[2], edge[1]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pendingMoves;
        vector<bool> visited(adjList.size());
        pendingMoves.push({0, node1});
        while (!pendingMoves.empty()){
            auto curr = pendingMoves.top();
            pendingMoves.pop();
            if (visited[curr.second])
                continue;
            if (curr.second == node2)
                return curr.first;
            visited[curr.second] = true;
            for (auto adj : adjList[curr.second])
                pendingMoves.push({adj.first + curr.first, adj.second});            
        }
        return -1;
    }
};

int main(){
    return 0;
}