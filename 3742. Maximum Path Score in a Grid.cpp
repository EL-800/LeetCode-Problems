#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int negInf = INT_MIN;
    int n, m;
    vector<vector<vector<int>>> memo;

    int dp(vector<vector<int>>& grid, int lastCost, int row = 0, int col = 0) {               
        if (row >= n || col >= m)
            return negInf;
        if (memo[row][col][lastCost] != -1) 
            return memo[row][col][lastCost];    
        int cost = lastCost - (grid[row][col] != 0);
        if (cost < 0)
            return negInf; 
        if (row == n - 1 && col == m - 1)
            return grid[row][col];            
        
        int right = dp(grid, cost, row, col + 1);
        int down = dp(grid, cost, row + 1, col);
        
        return memo[row][col][lastCost] = max(down, right) + grid[row][col];
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        memo.assign(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));   
        int ans = dp(grid, k);
        return ans < 0 ? - 1 : ans;
    }
};

int main() {
    vector<vector<int>> c = {{0, 1},{1, 2}};
    int k = 1;
    Solution s;
    cout << s.maxPathScore(c, k);
    return 0;
}