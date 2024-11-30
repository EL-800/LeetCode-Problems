#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree, outDegree;        
        stack<int> pendings;
        for (auto pair : pairs) {
            graph[pair[0]].push_back(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }
        int startNode = pairs[0][0];
        for (auto node : graph) {
            int key = node.first;
            if (outDegree[key] > inDegree[key]) {
                startNode = key;
                break;
            }                
        }
        vector<int> path;
        pendings.push(startNode);
        while (!pendings.empty()) {
            int currNode = pendings.top();
            if (graph[currNode].empty()) {
                path.push_back(currNode);
                pendings.pop();
            }
            else {
                pendings.push(graph[currNode].back());
                graph[currNode].pop_back();                
            }
        }
        reverse(path.begin(), path.end());
        vector<vector<int>> ans;
        for (int i = 0; i < path.size() - 1; i++) 
            ans.push_back({path[i], path[i + 1]});
        return ans;        
    }
};

int main() {
    return 0;
}