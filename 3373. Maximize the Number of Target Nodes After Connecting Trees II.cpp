#include <bits/stdc++.h>

using namespace std;

class Solution {
private:        
    void BuildGraph(vector<vector<int>> &graph, vector<vector<int>> &edges) {
         for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }

    int DFS(vector<vector<int>> &graph, vector<bool> &isEven, bool isValid = true, int current = 0, int parent = -1) {  
        isEven[current] = isValid;      
        int count = isValid;
        for (int adj : graph[current]) {
            if (adj == parent)
                continue;
            count += DFS(graph, isEven, !isValid, adj, current);
        }
        return count;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> graph1(n), graph2(m);                
        
        BuildGraph(graph2, edges2);
        BuildGraph(graph1, edges1);  

        vector<bool> isEven(max(n, m));
        int countG2 = DFS(graph2, isEven);
        countG2 = max(m - countG2, countG2);        
        
        int countG1 = DFS(graph1, isEven);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) 
            ans[i] = (isEven[i] ? countG1 : n - countG1) + countG2;
        return ans;
    }
};

int main() {
    return 0;
}