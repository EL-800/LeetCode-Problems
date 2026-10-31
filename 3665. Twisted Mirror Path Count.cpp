#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;
    int n, m;        
    vector<vector<vector<int>>> memo;
    int dp(vector<vector<int>>& grid, int row = 0, int col = 0, int dir = 0) {
        if(row >= n || col >= m)
            return 0;        
        if(row == n - 1 && col == m - 1)
            return 1;        
        if(memo[row][col][dir] != -1)
            return memo[row][col][dir];

        if(grid[row][col]){
            if(!dir)
                memo[row][col][dir] = dp(grid, row + 1, col, 1);
            else
                memo[row][col][dir] = dp(grid, row, col + 1, 0);            
        }
        else
            memo[row][col][dir] = (dp(grid, row, col + 1, 0) + dp(grid, row + 1, col, 1)) % mod;

        return memo[row][col][dir];
    }

    int uniquePaths(vector<vector<int>>& grid) {        
        n = grid.size(), m = grid[0].size();
        memo.assign(n, vector<vector<int>>(m, {-1, -1}));
        return dp(grid);
    }
};

int main() {
    return 0;
}