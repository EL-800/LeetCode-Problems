#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<int>> grid;        

    inline void MarkCells(int row, int col, int moveR, int moveC) {
        row += moveR, col += moveC;
        for (;row < m && row >= 0 && col < n && col >= 0 && grid[row][col] != 2; row += moveR, col += moveC)
            grid[row][col] = 1;                    
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {   
        this->m = m, this->n = n;
        grid.assign(m, vector<int>(n));     
        for (auto wall : walls) 
            grid[wall[0]][wall[1]] = 2;        
        for (auto guard : guards) {
            grid[guard[0]][guard[1]] = 2;
            MarkCells(guard[0], guard[1], 1, 0);
            MarkCells(guard[0], guard[1], 0, 1);
            MarkCells(guard[0], guard[1], -1, 0);
            MarkCells(guard[0], guard[1], 0, -1);
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) 
                ans += grid[i][j] == 0;
        }
        return ans;
    }
};

int main() {
    return 0;
}