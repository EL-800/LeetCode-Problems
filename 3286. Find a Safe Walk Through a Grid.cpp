#include <bits/stdc++.h>

using namespace std;

class Solution {
private: 
    int n, m;
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<vector<bool>>> memo;

    bool DFS(vector<vector<int>>& grid, int health, int row = 0, int col = 0) {                
        if (row == n - 1 && col == m - 1)
            return true;                

        memo[row][col][health] = true;
        for (auto &[moveR, moveC] : moves) {
            int adjRow = row + moveR, adjCol = col + moveC;
            if (adjRow < 0 || adjRow >= n)
                continue;
            if (adjCol < 0 || adjCol >= m)
                continue;            
            
            int adjHealth = health - grid[adjRow][adjCol];
            if (adjHealth <= 0)
                continue;
            if (memo[adjRow][adjCol][adjHealth])
                continue;
            if (DFS(grid, adjHealth, adjRow, adjCol))
                return true;
        }

        return false;
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size(), m = grid[0].size();
        memo.assign(n, vector<vector<bool>>(m, vector<bool>(health + 1, false)));
        return DFS(grid, health - grid[0][0]);
    }
};


int main() {
    vector<vector<int>> grid = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    Solution s;
    cout << s.findSafeWalk(grid, 1);
    return 0;
}