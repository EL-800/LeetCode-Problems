#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<int> parents;

    int FindParent(int u) {
        if (parents[u] == u)
            return u;
        return parents[u] = FindParent(parents[u]);
    }

    bool Join(int u, int v) {
        int parentU = FindParent(u), parentV = FindParent(v);
        parents[parentV] = parentU;
        return parentU != parentV;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();        
        parents.resize(n + 1);
        for (int i = 0; i < n; i++) 
            parents[i] = i;        
        for (auto edge : edges) {
            if (!Join(edge[0], edge[1]))
                return edge;
        }
        return vector<int>();
    }
};

int main() {
    return 0;
}