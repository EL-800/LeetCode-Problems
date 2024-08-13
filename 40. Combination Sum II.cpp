#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void Search(vector<vector<int>>& ans, unordered_map<int, int>::iterator e, unordered_map<int, int>::iterator ind, vector<int>& comb, int target) {
        if (target < 0)
            return;
        if (target == 0) {
            ans.push_back(comb);
            return;
        } 
        if (ind == e)
            return;             
        auto [v, f] = *ind;  
        int n = min(f, target / v);
        for (int i = 0; i <= n; i++) {
            int size = comb.size();            
            for (int j = 0; j < i; j++)
                comb.push_back(v);
            Search(ans, e, next(ind), comb, target - v * i);            
            comb.resize(size);
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> freq;
        for(int candidate : candidates)
            freq[candidate]++;
        vector<vector<int>> ans;
        vector<int> comb;
        Search(ans, freq.end(), freq.begin(), comb, target);
        return ans;
    }
};

int main() {
    vector<int> c = {1,2,2};
    Solution s;
    s.combinationSum2(c, 5);
    return 0;
}