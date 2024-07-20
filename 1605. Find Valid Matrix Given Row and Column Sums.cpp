#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        int rowInd = 0, colInd = 0;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        while (rowInd < n && colInd < m) {
            int x = min(rowSum[rowInd], colSum[colInd]);            
            rowSum[rowInd] -= x;
            colSum[colInd] -= x;
            matrix[rowInd][colInd] = x;
            rowInd += rowSum[rowInd] == 0;
            colInd += colSum[colInd] == 0;
        }
        return matrix;
    }
};

int main() {
    return 0;
}