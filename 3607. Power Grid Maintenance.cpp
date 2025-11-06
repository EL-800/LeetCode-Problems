#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> graph;
    unordered_map<int, set<int>> networks;
    vector<int> nodeId;

    void DFS(int curr, int id) {
        if (nodeId[curr] != -1)
            return;
        nodeId[curr] = id;
        networks[id].insert(curr);

        for (int adj : graph[curr]) 
            DFS(adj, id);                    
    }

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {        
        graph.assign(c + 1, vector<int>());
        nodeId.assign(c + 1, -1);

        for (auto connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }

        int currId = 0;
        for (int i = 1; i <= c; i++) {
            if (nodeId[i] != -1)
                continue;
            DFS(i, currId);
            currId++;
        }

        vector<int> ans;
        for (auto query : queries) {
            int networkId = nodeId[query[1]];
            if (query[0] == 2) {                
                if (networks[networkId].count(query[1]))
                    networks[networkId].erase(query[1]);
                continue;
            }
            
            if (networks[networkId].empty())
                ans.push_back(-1);
            else if (networks[networkId].count(query[1]))
                ans.push_back(query[1]);
            else
                ans.push_back(*networks[networkId].begin());                
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> c = {{1,2},{2,3},{3,4},{4,5}};
    vector<vector<int>> q = {{1,3},{2,1},{1,1},{2,2},{1,2}};

    Solution s;
    s.processQueries(5, c, q);
    return 0;
}