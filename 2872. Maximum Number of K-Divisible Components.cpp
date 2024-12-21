#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int k;
    vector<vector<int>> graph; 
    vector<long long> lValues;

    int TransverseGraph(vector<long long> &values, int curr = 0, int parent = - 1) {
        if (graph[curr].size() == 1 && parent != -1) {
            if (values[curr] % k) {
                values[parent] += values[curr];
                return 0;
            }
            return 1;
        }
        int sum = 0;
        for (int adj : graph[curr]) {
            if (adj != parent)                
                sum += TransverseGraph(values, adj, curr);
        }
        if (values[curr] % k && parent != -1) {
            values[parent] += values[curr];
            return sum;
        }
        return sum + 1;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->k = k;
        graph.resize(n);
        lValues.assign(values.begin(), values.end());        
        for (auto edge : edges) {
            int node1 = edge[0], node2 = edge[1];            
            graph[node1].push_back({node2});
            graph[node2].push_back({node1});
        }
        return TransverseGraph(lValues);
    }
};

int main() {
    return 0;
}