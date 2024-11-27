#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int BFS(vector<vector<int>>& road) {
        int n = road.size();
        vector<int> vis(n, -1);
        queue<int> pending;
        pending.push(0);
        vis[0] = 0;
        while (!pending.empty()) {
            int curr = pending.front();
            pending.pop();
            if (curr == n - 1)
                return vis[curr];
            for (int adj : road[curr]) {
                if (vis[adj] == -1) {
                    vis[adj] = vis[curr] + 1;
                    pending.push(adj);
                }                                    
            }
        }
        return -1;
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> road(n, vector<int>());
        vector<int> ans;        
        for (int i = 1; i < n; i++) 
            road[i - 1].push_back(i);                    
        for (auto q : queries) {            
            road[q[0]].push_back(q[1]);            
            ans.push_back(BFS(road));
        }
        return ans;
    }
};

int main() {
    return 0;
}