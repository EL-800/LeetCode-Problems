#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int dp(vector<vector<int>> &memo, vector<int> &totalSums, int i = 0, int m = 1) {
        if (i >= totalSums.size())
            return 0;
        if (memo[i][m] != -1)
            return memo[i][m];
        for (int x = 1; x <= 2 * m; x++) 
            memo[i][m] = max(memo[i][m], totalSums[i] - dp(memo, totalSums, i + x, max(m, x)));
        return memo[i][m];        
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        vector<int> totalSums(n);
        totalSums[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) 
            totalSums[i] += totalSums[i + 1] + piles[i];
        return dp(memo, totalSums);
    }
};

int main() {
    return 0;
}