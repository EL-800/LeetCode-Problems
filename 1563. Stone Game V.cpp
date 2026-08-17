#include <bits/stdc++.h>

using namespace std;

class Solution {
private:        
    int memo[502][502], prefixSum[502];

    int dp(int left, int right) {
        if (memo[left][right] != -1) 
            return memo[left][right];

        int curr = 0;
        for (int i = left; i <= right; i++) {
            int leftSum = prefixSum[i + 1] - prefixSum[left], rightSum = prefixSum[right + 1] - prefixSum[i + 1];

            if (leftSum >= rightSum)
                curr = max(curr, rightSum + dp(i + 1, right));
            if (leftSum <= rightSum)
                curr = max(curr, leftSum + dp(left, i));

            if (2 * min(leftSum, rightSum) <= curr)
                break;
        }

        return memo[left][right] = curr;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(memo, -1, sizeof(memo));
        memset(prefixSum, 0, sizeof(prefixSum));

        for (int i = 1; i <= n; i++) 
            prefixSum[i] = prefixSum[i - 1] + stoneValue[i - 1];        

        return dp(0, n - 1);
    }
};

int main() {
    return 0;
}