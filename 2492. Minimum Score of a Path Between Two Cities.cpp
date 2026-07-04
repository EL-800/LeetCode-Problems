#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<pair<int, int>>> graph;
    vector<bool> visited;

    int FindMinEdge(int currNode) {
        if (visited[currNode])
            return INT_MAX;
        visited[currNode] = true;
        int currNodeMin = INT_MAX;
        for (auto adj : graph[currNode])
            currNodeMin = min({ adj.second, FindMinEdge(adj.first), currNodeMin });
        return currNodeMin;
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {
        graph.resize(n + 1);
        visited.resize(n + 1);
        for (vector<int> i : roads) {
            graph[i[0]].push_back({ i[1], i[2] });
            graph[i[1]].push_back({ i[0], i[2] });            
        }
        return FindMinEdge(1);
    }
};

int main() {
    return 0;
}