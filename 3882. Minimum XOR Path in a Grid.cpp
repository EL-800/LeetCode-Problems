#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<vector<int>>> memo;

    int DP(vector<vector<int>>& grid, int row = 0, int col = 0, int currVal = 0) {        
        if (row >= n || col >= m)
            return INT_MAX;
        if(row == n - 1 && col == m - 1) 
            return currVal ^ grid[row][col];
        if (memo[row][col][currVal] != -1)
            return memo[row][col][currVal];
        
        return memo[row][col][currVal] = min(DP(grid, row + 1, col, currVal ^ grid[row][col]), 
            DP(grid, row, col + 1, currVal ^ grid[row][col]));
    }

public:
    int minCost(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memo.assign(n, vector<vector<int>>(m, vector<int>(1024, -1)));
        return DP(grid);
    }
};

int main() {
    return 0;
}