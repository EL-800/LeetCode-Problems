#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> path;

    int DFS(vector<vector<int>>& graph, int currNode) {
        if (path[currNode] == 1)
            return 1;        
        if (path[currNode] == 2)
            return 2;
        if (graph[currNode].empty()) {
            path[currNode] = 2;
            return 2;
        }
        path[currNode] = 1;
        int allTerminal = 2;
        for (int adj : graph[currNode]) 
            allTerminal = min(allTerminal, DFS(graph, adj));        
        return path[currNode] = allTerminal;
    }


public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = (int)graph.size();
        path.assign(n, 0);
        for (int i = 0; i < n; i++)
            DFS(graph, i);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (path[i] == 2)
                ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    return 0;
}