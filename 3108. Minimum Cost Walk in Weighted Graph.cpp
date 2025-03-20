#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        vector<int> parents, setValue;

        int FindParent(int u) {
            if (parents[u] == u)
                return u;
            return parents[u] = FindParent(parents[u]);
        }

        void Union(int u, int v, int w) {
            int parentU = FindParent(u), parentV = FindParent(v);            
            parents[parentV] = parents[parentU];
            setValue[parentU] &= setValue[parentV] & w;                            
        }

    public:
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {  
            parents.reserve(n);
            setValue.reserve(n);          
            for (int i = 0; i < n; i++) {
                parents.push_back(i);
                setValue.push_back(INT_MAX);
            }
            for (auto edge : edges)
                Union(edge[0], edge[1], edge[2]);
            vector<int> ans;
            for (auto query : queries) {
                int u = FindParent(query[0]), v = FindParent(query[1]);
                ans.push_back(parents[u] == parents[v] ? setValue[u] : -1);
            }
            return ans;
        }
    };

int main() {
    return 0;
}