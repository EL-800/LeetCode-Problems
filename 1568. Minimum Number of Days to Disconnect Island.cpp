#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void DFS(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
            return;
        if (!grid[row][col])
            return;
        grid[row][col] = false;
        for (auto [moveR, moveC] : moves)
            DFS(grid, row + moveR, col + moveC);        
    }

    int CountIslands(vector<vector<int>> grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    DFS(grid, i, j);
                    islands++;
                }                    
            }                
        }
        return islands;
    }

public:
    int minDays(vector<vector<int>>& grid) {
        if (CountIslands(grid) != 1)
            return 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    if (CountIslands(grid) != 1)
                        return 1;
                    grid[i][j] = 1;
                }                    
            }                
        }
        return 2;
    }
};

int main () {
    return 0;
}