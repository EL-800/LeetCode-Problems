#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> grid(n, vector<int>(n));       
        for (auto query : queries) {
            int row1 = query[0], col1 = query[1], row2 = query[2], col2 = query[3];
            for (; row1 <= row2; row1++) {
                grid[row1][col1]++;
                if (col2 + 1 < n)
                    grid[row1][col2 + 1]--;
            }
        }
        
        for (int i = 0; i < n; i++) {            
            for (int j = 1; j < n; j++) 
                grid[i][j] += grid[i][j - 1];            
        }

        return grid;
    }
};

int main() {
    return 0;
}