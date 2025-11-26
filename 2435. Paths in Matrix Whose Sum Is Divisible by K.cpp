#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
const int mod = 1e9 + 7;
    int n, m, k;
    vector<vector<vector<int>>> memo; 

    int dp(vector<vector<int>>& grid, int row = 0, int col = 0, int reminder = 0) {        
        if (row >= n || col >= m)
            return 0;

        int curr = grid[row][col];
        if (row == n - 1 && col == m - 1)
            return (k - (curr % k) + reminder) % k == 0;
        if (memo[row][col][reminder] != -1) 
            return memo[row][col][reminder];
                
        return memo[row][col][reminder] = (dp(grid, row + 1, col, (k - (curr % k) + reminder) % k) +
            dp(grid, row, col + 1, (k - (curr % k) + reminder) % k)) % mod;
    }

public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        this->k = k;
        memo.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return dp(grid) % mod;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = {{5,2,4},{3,0,5},{0,7,2}};
    cout << s.numberOfPaths(a, 3);
    return 0;
}