#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n, k;
    vector<vector<long long>> memo;

    long long dp(vector<int>& nums, int ind, int prev, int req) {
        if(ind >= nums.size()) 
            return 0;
        if(memo[ind][prev] != -1) 
            return memo[ind][prev];

        long long skip = 0, take = 0;
        if(prev == k)
            skip = dp(nums, ind + 1, k, req);        
        
        long long curProd;
        if(prev == k) 
            curProd = nums[ind];
        else 
            curProd = (prev * nums[ind]) % k; 

        take += (curProd == req);
        take += dp(nums, ind + 1, curProd, req);
        return memo[ind][prev] = take + skip;
    }

    vector<long long> resultArray(vector<int>& nums, int k) {
        n = nums.size();
        this->k = k;
        vector<long long> ans(k, 0);        

        for(int& num : nums) 
            num %= k;

        for(int r = 0; r < k; r++){            
            memo.assign(n, vector<long long>(k + 1, -1));
            ans[r] = dp(nums, 0, k, r);            
        }

        return ans;
    }
};

int main() {
    return 0;
}