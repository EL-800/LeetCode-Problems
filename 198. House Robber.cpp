#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<int> dp;

    int FindMax(vector<int>& nums, int currInd = 0) {
        if (currInd >= n)
            return 0;
        if (dp[currInd] != -1)
            return dp[currInd];
        return dp[currInd] = max(FindMax(nums, currInd + 1), FindMax(nums, currInd + 2) + nums[currInd]);

    }

public:
    int rob(vector<int>& nums) {
        n = (int)nums.size();
        dp.assign(n, -1);
        return FindMax(nums);
    }
};

int main(){
    return 0;
}