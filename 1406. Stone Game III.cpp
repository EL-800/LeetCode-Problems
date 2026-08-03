#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int negInf = INT_MIN;
    int n;
    vector<int> memo;

    int FindMax(vector<int>& nums, int ind = 0) {
        if (ind == n)
            return 0;
        if (memo[ind] != negInf)
            return memo[ind];

        int currSum = 0;
        for (int i = ind; i < n && i < ind + 3; i++) {
            currSum += nums[i];
            memo[ind] = max(memo[ind], currSum - FindMax(nums, i + 1));
        }

        return memo[ind];
    }

public:
    string stoneGameIII(vector<int>& nums) {
        n = nums.size();
        memo.assign(n, negInf);
        
        int best = FindMax(nums);
        if (best > 0)
            return "Alice";
        else if (best == 0)
            return "Tie";
        else
            return "Bob";
    }
};

int main() {
    return 0;
}