#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n);   
        sort(nums.begin(), nums.end());        
        for (int i = 0; i < n; i++){
            for (int j = i; j >= 0; j--){
                if (nums[i] % nums[j] == 0) {
                    vector<int> aux = memo[j];
                    aux.push_back(nums[i]);
                    memo[i] = aux.size() > memo[i].size() ? aux : memo[i];
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < memo.size(); i++)
            ans = memo[i].size() > ans.size() ? memo[i] : ans;
        return ans;
    }
};

int main(){     
    Solution s;
    vector<int> c = {1,2,4,8};
    s.largestDivisibleSubset(c);
    return 0;
}