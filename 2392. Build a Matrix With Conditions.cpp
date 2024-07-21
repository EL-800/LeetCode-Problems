#include <bits/stdc++.h>

using namespace std; 

class Solution {
private:
    bool DFS(vector<vector<int>>& graph, vector<int>& visited, vector<int>& topo, int currNode) {
        if (visited[currNode] == 2)
            return true;  
        if (visited[currNode] == 1)
            return false;
        visited[currNode] = 1;    
        bool flag = true;
        for (int adjNode : graph[currNode]) 
            flag &= DFS(graph, visited, topo, adjNode);
        topo.push_back(currNode);
        visited[currNode] = 2;                 
        return flag;
    }

    vector<int> TopologicalSort(int k, vector<vector<int>> &conditions) {
        vector<vector<int>> graph(k + 1);
        for (int i = 0; i < conditions.size(); i++) 
            graph[conditions[i][0]].push_back(conditions[i][1]);        
        vector<int> visited(graph.size());
        vector<int> topo;        
        for (int i = 1; i < graph.size(); i++) {
            if (!visited[i]) {
                if (!DFS(graph, visited, topo, i))
                    return vector<int>();                                    
            }
        }
        reverse(topo.begin(), topo.end());
        return topo;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {                        
        vector<int> rowSort = TopologicalSort(k, rowConditions), colSort = TopologicalSort(k, colConditions);
        if (rowSort.empty() || colSort.empty())
            return vector<vector<int>>();
        vector<int> bucketCol(k + 1);
        for (int i = 0; i < k; i++) 
            bucketCol[colSort[i]] = i;
        vector<vector<int>> ans(k, vector<int>(k));
        for (int i = 0; i < k; i++) 
            ans[i][bucketCol[rowSort[i]]] = rowSort[i];        
        return ans;
    }
};

int main() {
    return 0;
}