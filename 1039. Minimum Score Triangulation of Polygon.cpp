#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int inf = 1e9;
    vector<vector<int>> memo;

    int dp(vector<int>& values, int i, int j) {
        if (j - i < 2) 
            return 0;
        if (memo[i][j] != -1) 
            return memo[i][j];

        int curr = inf;
        for (int k = i + 1; k < j; k++) 
            curr = min(curr, dp(values, i, k) + values[i] * values[k] * values[j] + 
            dp(values, k, j));        
        return memo[i][j] = curr;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memo.assign(n, vector<int>(n, -1));
        return dp(values, 0, n - 1);
    }
};

int main() {
    return 0;
}