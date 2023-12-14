#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> onesRow(n), onesCol(m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                onesRow[i] += grid[i][j];
                onesCol[j] += grid[i][j];
            }
        }
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int zerosRow = n - onesRow[i], zerosCol = m - onesCol[j];
                ans[i][j] = onesRow[i] + onesCol[j] - zerosRow - zerosCol;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}