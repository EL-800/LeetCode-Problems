#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, k, subArrN = 3;
    vector<int> sums;
    vector<vector<vector<int>>> memo;

    vector<int> DP(int indArr = 0, int indSub = 0) {
        if (indArr > n - k)
            return {0, -1, -1, -1};
        if (indSub == subArrN)
            return {0, -1, -1, -1};
        if (memo[indArr][indSub][0] != -1)
            return memo[indArr][indSub];
        vector<int> left = DP(indArr + k, indSub + 1);
        left[0] += sums[indArr + k] - sums[indArr];
        left[indSub + 1] = indArr;
        vector<int> right = DP(indArr + 1, indSub);
        return memo[indArr][indSub] = left[0] >= right[0] ? left : right;
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {        
        n =  nums.size();
        this->k = k;
        sums.resize(n + 1);
        memo.assign(n, vector<vector<int>>(subArrN, vector<int>(4, -1)));
        for (int i = 1; i <= n; i++)
            sums[i] = nums[i - 1] + sums[i - 1];
        vector<int> ans = DP();
        return vector<int>(ans.begin() + 1, ans.end());
    }
};

int main() {
    return 0;
}