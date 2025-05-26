#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> graph;
    string colors;    

    int DFS(vector<int> &visited, char color, int currNode) {    
        if (visited[currNode] != -1)
            return visited[currNode];    
        int bestAdjPath = 0;
        for (int adj : graph[currNode]) 
            bestAdjPath = max(bestAdjPath, DFS(visited, color, adj));        
        return visited[currNode] = bestAdjPath + (colors[currNode] == color);
    }

    int MaxPathWithColor(char color) {
        int maxPath = 0;
        vector<int> visited(n, -1);
        for (int i = 0; i < n; i++) 
            maxPath = max(maxPath, DFS(visited, color, i));        
        return maxPath;
    }

    bool hasCycleAux(vector<int> &visited, int curr) {
        if (visited[curr] == 1)
            return true;
        if (visited[curr] == 2)
            return false;        
        visited[curr] = 1;
        for (int adj : graph[curr]) {
            if (hasCycleAux(visited, adj))
                return true;
        }
        visited[curr] = 2;
        return false;        
    }

    bool hasCycle() {
        vector<int> visited(n);
        for (int i = 0; i < n; i++)  {
            if (!visited[i] && hasCycleAux(visited, i))
                return true;
        }
        return false;
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        n = colors.length();
        this->colors = colors;
        graph.assign(n, vector<int>());        
        for (auto edge : edges)
            graph[edge[0]].push_back(edge[1]);
        if (hasCycle())
            return -1;
        int ans = 0;
        for (int i = 'a'; i <= 'z'; i++)
            ans = max(ans, MaxPathWithColor(i));
        return ans;
    }
};

int main() {
    string s = "abaca";
    vector<vector<int>> a = {{0,1},{0,2},{2,3},{3,4}}; 
    Solution b;
    cout << b.largestPathValue(s, a);   
    return 0;
}