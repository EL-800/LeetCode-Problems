#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> minRows(n, INT_MAX), maxCols(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                minRows[i] = min(minRows[i], matrix[i][j]);
                maxCols[j] = max(maxCols[j], matrix[i][j]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == minRows[i] && matrix[i][j] == maxCols[j])
                    ans.push_back(matrix[i][j]);
            }            
        }
        return ans;
    }
};

int main() {
    return 0;
}