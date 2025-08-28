#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {            
            vector<int> diagonal;
            for (int row = i, col = 0; row < n; row++, col++) 
                diagonal.push_back(grid[row][col]);
            sort(diagonal.rbegin(), diagonal.rend());
            for (int row = i, col = 0; row < n; row++, col++) 
                grid[row][col] = diagonal[col];                        
        }

        for (int i = 1; i < m; i++) {            
            vector<int> diagonal;
            for (int row = 0, col = i; col < m; row++, col++) 
                diagonal.push_back(grid[row][col]);
            sort(diagonal.begin(), diagonal.end());
            for (int row = 0, col = i; col < m; row++, col++) 
                grid[row][col] = diagonal[row];                        
        }

        return grid;
    }
};

int main() {
    return 0;
}