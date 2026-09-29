#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    int memo[102][102][202];

    bool dp(vector<vector<char>>& grid, int row = 0, int col = 0, int count = 0) {
        if (row < 0 || row >= n)
            return false;
        if (col < 0 || col >= m)
            return false;
        count += grid[row][col] == '(' ? 1 : -1;
        if (count < 0)
            return false;        
        if (row == n - 1 && col == m - 1)
            return count == 0;

        if (memo[row][col][count] != -1) 
            return memo[row][col][count];

        return memo[row][col][count] = dp(grid, row + 1, col, count) || dp(grid, row, col + 1, count);
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(memo, -1, sizeof(memo));

        return dp(grid);
    }
};

int main() {
    return 0;
}