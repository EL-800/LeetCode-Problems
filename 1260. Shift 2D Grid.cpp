#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), last = 0;        

        while (k--) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {                
                    if (!i && !j) {
                        last = grid[0][0];
                        grid[0][0] = grid[n - 1][m - 1];
                    }                                    
                    else if (!j) {
                        int aux = grid[i][0];
                        grid[i][0] = last;
                        last = aux;                    
                    }                
                    else {
                        int aux = grid[i][j];
                        grid[i][j] = last;
                        last = aux;
                    }
                }
            }
        }

        return grid;
    }
};

int main() {
    return 0;
}