#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, target;
    vector<int> memo;

    int dp(vector<int>& nums, int ind = 0) {
        if (ind == n - 1)
            return 0;
        if (memo[ind] != -2)
            return memo[ind];

        memo[ind] = -1;
        for (int i = ind + 1; i < n; i++) {
            if (abs(nums[ind] - nums[i]) > target)
                continue;
            int next = dp(nums, i);            
            if (next != -1)
                memo[ind] = max(memo[ind], next + 1);
        }

        return memo[ind];
    }

public:
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        this->target = target;
        memo.assign(n, -2);
        return dp(nums);
    }
};

int main() {
    return 0;
}