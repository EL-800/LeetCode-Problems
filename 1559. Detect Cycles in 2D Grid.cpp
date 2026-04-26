#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool DFS(vector<vector<char>>& grid, int row, int col, char search, int lastRow = -1, int lastCol = -1) {
        if (row < 0 || col < 0)
            return false;
        if (row >= n || col >= m)
            return false;                
        if (grid[row][col] == 'A')
            return true;
        if (grid[row][col] != search)
            return false;
        grid[row][col] = 'A';

        for (auto [moveRow, moveCol] : moves) {
            int adjRow = row + moveRow, adjCol = col + moveCol;
            if (adjRow == lastRow && adjCol == lastCol)
                continue;
            if (DFS(grid, adjRow, adjCol, search, row, col))
                return true;
        }
        
        grid[row][col] = 'B';
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'B')
                    continue;
                if (DFS(grid, i, j, grid[i][j]))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<char>> c = {{'a','b','b'},{'b','z','b'},{'b','b','a'}};
    Solution s;
    cout << s.containsCycle(c);
    return 0;
}