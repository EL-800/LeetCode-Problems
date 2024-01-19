#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<int>> dp;
    const vector<pair<int, int>> moves = { {1, 1}, {1, 0}, {1, -1} };

    int FindMin(vector<vector<int>>& matrix, int row, int col) {
        if (row < 0 || row >= n)
            return INT16_MAX;
        if (col < 0 || col >= m)
            return INT16_MAX;
        if (row == n - 1)
            return matrix[row][col];
        if (dp[row][col] != INT16_MAX)
            return dp[row][col];        
        for (pair<int, int> i : moves)
            dp[row][col] = min(dp[row][col], FindMin(matrix, row + i.first, col + i.second) + matrix[row][col]);
        return dp[row][col];
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp.assign(n, vector<int>(m, INT16_MAX));
        int ans = INT16_MAX;
        for (int i = 0; i < m; i++) 
            ans = min(ans, FindMin(matrix, 0, i));        
        return ans;
    }
};

int main(){
    return 0;
}