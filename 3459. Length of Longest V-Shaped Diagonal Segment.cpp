#include <bits/stdc++.h>

using namespace std;

class Solution {
private:   
    int n, m;
    vector<pair<int, int>> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int memo[500][500][4][2];

    bool IsOut(int row, int col) {
        return row < 0 || row >= n || col < 0 || col >= m;
    }

    int DP(vector<vector<int>> &grid, int row, int col, int dir, bool hasTurn = false, int nextVal = 2) {        
        if (memo[row][col][dir][hasTurn] != - 1)
            return memo[row][col][dir][hasTurn];
        int currSol = 1;

        int adjRow = row + directions[dir].first, adjCol = col + directions[dir].second;        
        if (!IsOut(adjRow, adjCol) && grid[adjRow][adjCol] == nextVal)
            currSol = max(currSol, DP(grid, adjRow, adjCol, dir, hasTurn, nextVal ^ 2) + 1);
        
        if (!hasTurn) {
            int nextDir = (dir + 1) % directions.size();
            currSol = max(currSol, DP(grid, row, col, nextDir, true, nextVal));
        }

        return memo[row][col][dir][hasTurn] = currSol;
    }

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for (int i=0; i<n; i++) 
            for(int j=0; j<m; j++)
                memset(memo[i][j], -1, sizeof(memo[i][j]));


        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 1)
                    continue;
                for (int d = 0; d < directions.size(); d++)
                    ans = max(ans, DP(grid, i, j, d));                    
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}