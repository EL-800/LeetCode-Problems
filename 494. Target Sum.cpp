#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, target;
    vector<unordered_map<int, int>> memo;

    int DP(vector<int> &nums, int currInd = 0, int currSum = 0) {
        if (currInd == n)
            return currSum == target;
        if (memo[currInd].count(currSum))
            return memo[currInd][currSum];
        return DP(nums, currInd + 1, currSum + nums[currInd]) + DP(nums, currInd + 1, currSum - nums[currInd]);        
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size(), this->target = target;
        memo.resize(n);        
        return DP(nums);
    }
};

int main() {
    return 0;
}