#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> subTreeXOR;
    vector<vector<int>> graph;
    vector<unordered_set<int>> descendants;

    int CalculateSubTreeXOR(int curr = 0, int parent = -1) {  
        descendants[curr].insert(curr);      
        for (int adj : graph[curr]) {
            if (adj == parent)
                continue;                 
            subTreeXOR[curr] ^= CalculateSubTreeXOR(adj, curr);  
            descendants[curr].insert(descendants[adj].begin(), descendants[adj].end());
        }
        return subTreeXOR[curr];
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        graph.resize(n);
        descendants.resize(n);
        subTreeXOR = nums;        
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int totalTreeXOR = CalculateSubTreeXOR(), ans = INT_MAX;        
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int firstTree = subTreeXOR[i], secondTree = subTreeXOR[j];
                if (descendants[i].count(j)) 
                    firstTree ^= secondTree;
                else if (descendants[j].count(i))
                    secondTree ^= firstTree;
                int thirdTree = totalTreeXOR ^ firstTree ^ secondTree;                            
                ans = min(ans, max({firstTree, secondTree, thirdTree}) - min({firstTree, secondTree, thirdTree}));
            }
        }
        return ans;
    }
};

int main() {
    vector<int> a = {1,5,5,4,11};
    vector<vector<int>> b = {{0,1},{1,2},{1,3},{3,4}};    
    Solution s;
    cout << s.minimumScore(a, b);
    return 0;
}