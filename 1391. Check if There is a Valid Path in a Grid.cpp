#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    //0 up 1 left 2 down 3 right 
    vector<vector<int>> in = {{1, 3}, {0, 2}, {0, 3}, {0, 1}, {2, 3}, {1, 2}};
    vector<vector<int>> out = {{1, 3}, {0, 2}, {1, 2}, {2, 3}, {0, 1}, {0, 3}};
    vector<vector<int>> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool DFS(vector<vector<int>>& grid, int row = 0, int col = 0, int dir = -1) {           
        if (row < 0 || col < 0)
            return false;
        if (row >= n || col >= m)
            return false;        
        if (grid[row][col] == -1)
            return false;
        auto &currIn = in[grid[row][col] - 1];
        auto &currOut = out[grid[row][col] - 1];
        if (dir != -1 && !count(currIn.begin(), currIn.end(), dir))        
            return false;
        if (row == n - 1 && col == m - 1)
            return true;
        grid[row][col] = -1;
        
        for (int dir : currOut) {
            int adjRow = row + moves[dir][0], adjCol = col + moves[dir][1];
            if (DFS(grid, adjRow, adjCol, dir))
                return true;
        }

        return false;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        return DFS(grid);
    }
};

int main() {
    Solution s;
    vector<vector<int>> c = {{1,2},{4,3}};
    cout << s.hasValidPath(c);
    return 0;
}