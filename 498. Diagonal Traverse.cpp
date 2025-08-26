#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), row = 0, col = 0, moveRow = -1, moveCol = 1;
        vector<int> ans;
        while (row != n - 1 || col != m - 1) {
            ans.push_back(mat[row][col]);
            if (row + moveRow < 0 || col + moveCol >= m) {
                if (col + 1 < m)
                    col++;
                else
                    row++;
                swap(moveRow, moveCol);
            }
            else if ((row + moveRow >= n || col + moveCol < 0)) {
                if (row + 1 < n)
                    row++;
                else
                    col++;
                swap(moveRow, moveCol);
            }
            else {
                row += moveRow;
                col += moveCol;
            }                           
        }
        ans.push_back(mat[row][col]);
        return ans;
    }
};

int main() {
    return 0;
}