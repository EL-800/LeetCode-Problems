#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:    
        vector<unordered_map<int, bool>> memo;
        
        bool dp(vector<int>& nums, int ind, int sum) {
            if (ind == nums.size())
                return false;
            if (sum < 0)
                return false;
            if (!sum)
                return true;
            if (memo[ind].count(sum))
                return memo[ind][sum]; 
            if (dp(nums, ind + 1, sum) || dp(nums, ind + 1, sum - nums[ind]))  
                return memo[ind][sum] = true;         
            return memo[ind][sum] = false;
        }

    public:
        bool canPartition(vector<int>& nums) {
            int totalSum = accumulate(nums.begin(), nums.end(), 0);
            memo.resize(nums.size());
            if (totalSum % 2)
                return false;
            return dp(nums, 0, totalSum / 2);
        }
    };

int main() {
    return 0;
}