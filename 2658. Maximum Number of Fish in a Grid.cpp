#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int DFS(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return 0;
        if (!grid[row][col])
            return 0;
        int fishes = grid[row][col];
        grid[row][col] = 0;        
        for (auto [moveR, moveC] : moves) 
            fishes += DFS(grid, row + moveR, col + moveC);        
        return fishes;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) 
                    ans = max(ans, DFS(grid, i, j));
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}