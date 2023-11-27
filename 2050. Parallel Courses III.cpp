#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int DFS(vector<vector<int>>& graph, vector<int>& time, vector<int>& vis, int currNode){
        if (vis[currNode] != - 1)
            return vis[currNode];        
        vis[currNode] = time[currNode];
        for (int nextNode : graph[currNode])
            vis[currNode] = max(vis[currNode], DFS(graph, time, vis, nextNode) + time[currNode]);        
        return vis[currNode];
    }

public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);
        vector<int> vis(n, -1);
        for (auto relation : relations)
            graph[relation[0] - 1].push_back(relation[1] - 1);        
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, DFS(graph, time, vis, i));        
        return ans;
    }
};

int main(){
    return 0;
}