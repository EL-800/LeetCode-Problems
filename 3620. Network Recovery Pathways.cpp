#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<vector<pair<int, int>>> graph;

    bool Dijsktra(vector<bool> &online, long long k, int maxWeight) {        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pendingMoves;
        vector<long long> weights(n, LLONG_MAX);
        weights[0] = 0; 
        pendingMoves.push({0, 0});

        while(!pendingMoves.empty()) {            
            auto [currWeight, currNode] = pendingMoves.top();
            pendingMoves.pop();
            if (currWeight > weights[currNode])
                continue;
            if (currNode == n - 1)
                return true;
            for (auto &[weight, adj] : graph[currNode]) {
                if (!online[adj])
                    continue;
                if (weight < maxWeight)
                    continue;
                if (currWeight + (long long)weight > k)
                    continue;
                if (weights[adj] < currWeight + (long long)weight)
                    continue;
                
                weights[adj] = currWeight + (long long)weight;
                pendingMoves.push({currWeight + (long long)weight, adj});
            }            
        }
        return false;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        int maxWeight = 0;
        graph.resize(n);

        for (auto &edge : edges) {
            maxWeight = max(maxWeight, edge[2]);
            graph[edge[0]].push_back({edge[2], edge[1]});        
        }        

        int left = 0, right = maxWeight, ans = -1;
        while (left <= right) {            
            int mid = left + (right - left) / 2;
            
            if (Dijsktra(online, k, mid)) {
                left = mid + 1;
                ans = mid;
            }
            else
                right = mid - 1;
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> c = {{0,1,5},{1,3,10},{0,2,3},{2,3,4}};
    vector<bool> b = {true,true,true,true};
    Solution s;
    s.findMaxPathScore(c, b, 10);
    return 0;
}