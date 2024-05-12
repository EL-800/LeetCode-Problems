#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int GetMaxLocal(vector<vector<int>>& grid, int row, int col){        
        int maxLocal = 0;
        for (int i = row - 1; i <= row + 1; i++){
            for (int j = col - 1; j <= col + 1; j++){
                maxLocal = max(maxLocal, grid[i][j]);
            }
        }
        return maxLocal;
    }

public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> locals(n - 2, vector<int>(m - 2));
        for (int i = 1; i < n - 1; i++){
            for (int j = 1; j < m - 1; j++){
                locals[i - 1][j - 1] = GetMaxLocal(grid, i, j);
            }
        }
        return locals;
    }
};

int main(){
    return 0;
}