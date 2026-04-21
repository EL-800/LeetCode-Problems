#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> parents;

    int Find(int v) {
        if (parents[v] == v)
            return v;
        return parents[v] = Find(parents[v]);
    }

    void Union(int u, int v) {
        int parentU = Find(u), parentV = Find(v);
        if (parentU == parentV)
            return;
        parents[parentV] = parentU;
    }

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parents.resize(n);
        
        for (int i = 0; i < n; i++)
            parents[i] = i;
        
        for (auto swap : allowedSwaps) 
            Union(swap[0], swap[1]);

        vector<unordered_map<int, int>> groupCount(n);

        for (int i = 0; i < n; i++) 
            groupCount[Find(i)][source[i]]++;        

        int ans = 0;
        for (int i = 0; i < source.size(); i++) {
            int parentSource = Find(i);            
            if (groupCount[parentSource].count(target[i])) {
                groupCount[parentSource][target[i]]--;
                if (!groupCount[parentSource][target[i]])
                    groupCount[parentSource].erase(target[i]);
            }
            else ans++;            
        }
        
        return ans;
    }
};

int main() {
    return 0;
}