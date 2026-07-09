#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> parents;

    int Find(int u) {
        if (parents[u] == u)
            return u;
        return parents[u] = Find(parents[u]);
    }

    void Union(int u, int v) {
        int parentU = Find(u), parentV = Find(v);
        parents[parentV] = parentU;
    }

public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parents.assign(n, 0);
        for (int i = 0; i < n; i++) 
            parents[i] = i;         
        
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff)
                Union(i - 1, i);
        }

        vector<bool> ans;
        for (auto &q : queries) {
            int u = q[0], v = q[1];            
            ans.push_back(parents[Find(u)] == parents[Find(v)]);
        }


        return ans;
    }
};

int main() {
    return 0;
}