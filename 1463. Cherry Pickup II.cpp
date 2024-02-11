#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<vector<int>>> memo;    

    int dp(vector<vector<int>>& grid, int r, int c1, int c2){
        if (r >= n  || c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
            return 0;                    
        if (memo[r][c1][c2] != -1)
            return memo[r][c1][c2];    
        int currSum = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];    
        for (int i = -1; i <= 1; i++){
            for (int j = -1; j <= 1; j++)
                memo[r][c1][c2] = max(memo[r][c1][c2], currSum + dp(grid, r + 1, c1 + i, c2 + j));            
        }
        return memo[r][c1][c2];
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memo.assign(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return dp(grid, 0, 0, m - 1);
    }
};

int main(){

}