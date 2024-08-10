#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void DFS(vector<vector<bool>>& grid, int currRow = 0, int currCol = 0) {
        if (currRow < 0 || currRow >= grid.size() || currCol < 0 || currCol >= grid.size())
            return;
        if (grid[currRow][currCol])
            return;
        grid[currRow][currCol] = true;
        for (auto [moveR, moveC] : moves) 
            DFS(grid, currRow + moveR, currCol + moveC);                    
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<bool>> modifiedGrid(n * 3, vector<bool>(n * 3));
        for (int nRow = 0, mRow = 0; nRow < n; nRow++, mRow += 3) {
            for (int nCol = 0, mCol = 0; nCol < n; nCol++, mCol += 3) {
                switch (grid[nRow][nCol]) {
                    case '/':
                        modifiedGrid[mRow][mCol + 2] = true;
                        modifiedGrid[mRow + 1][mCol + 1] = true;
                        modifiedGrid[mRow + 2][mCol] = true;
                    break;
                    case '\\':
                        modifiedGrid[mRow][mCol] = true;                        
                        modifiedGrid[mRow + 1][mCol + 1] = true;
                        modifiedGrid[mRow + 2][mCol + 2] = true;
                    break;
                }                
            }
        }        
        int ans = 0;
        for (int i = 0; i < modifiedGrid.size(); i++) {
            for (int j = 0; j < modifiedGrid.size(); j++) {
                if (!modifiedGrid[i][j]) {
                    DFS(modifiedGrid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}