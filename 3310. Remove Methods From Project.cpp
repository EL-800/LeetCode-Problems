#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> graph;
    vector<int> suspicious; //0 unvisited 1 suspicious 2 visited

    void MarkSuspiciousNodes(int curr) {
        if (suspicious[curr])
            return;
        suspicious[curr] = 1;
        
        for (int adj : graph[curr]) 
            MarkSuspiciousNodes(adj);
        
    }

    bool IsConnectedToSuspicious(int curr) {
        if (suspicious[curr] == 1)
            return true;
        else if (suspicious[curr] == 2)
            return false;
        suspicious[curr] = 2;

        for (int adj : graph[curr]) {
            if (IsConnectedToSuspicious(adj))
                return true;
        }

        return false;
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        graph.resize(n);
        suspicious.assign(n, 0);
        for (auto &invocation : invocations) 
            graph[invocation[0]].push_back(invocation[1]);        

        MarkSuspiciousNodes(k);

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i] && IsConnectedToSuspicious(i)) {
                ans.resize(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }

        }
        
        for (int i = 0; i < n; i++) {
            if (suspicious[i] != 1)
                ans.push_back(i);
        }

        return ans;
    }
};

int main() {
    return 0;
}