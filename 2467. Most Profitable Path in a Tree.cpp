#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:        
        vector<vector<int>> graph;
        vector<int> bobPath;

        int GetBobPath(int obj, int curr = 0, int parent = -1) {
            if (curr == obj)
                return bobPath[curr] = 0;
            for (auto adj : graph[curr]) {
                if (adj == parent)
                    continue;
                int adjPath = GetBobPath(obj, adj, curr);
                if (adjPath != -1)
                    return bobPath[curr] = adjPath + 1; 
            }
            return -1;
        }        

        int AliceBestPath(vector<int> &amount, int curr = 0, int parent = -1, int steps = 0) {
            int currAmount = 0;
            if (steps == bobPath[curr])
                currAmount = amount[curr] / 2;
            else if (steps < bobPath[curr])
                currAmount = amount[curr];            
            if (curr && graph[curr].size() == 1)
                return currAmount;
            int bestPath = INT_MIN;
            for (auto adj : graph[curr]) {
                if (adj == parent)
                    continue;
                bestPath = max(bestPath, AliceBestPath(amount, adj, curr, steps + 1));
            }
            return bestPath + currAmount;
        }

    public:
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            int n = amount.size();            
            bobPath.assign(n, INT_MAX);
            graph.resize(n);            
            for (auto edge : edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
            GetBobPath(bob);
            return AliceBestPath(amount);
        }
    };

int main() {
    vector<vector<int>> a = {{0,1},{1,2},{1,3},{3,4}};
    vector<int> b = {-2,4,2,-4,6};
    Solution s;
    cout << s.mostProfitablePath(a, 3, b);
    return 0;
}