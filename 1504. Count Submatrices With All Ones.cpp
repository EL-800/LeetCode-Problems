#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> maxRange(n, vector<int>(m + 1));
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (mat[i][j])
                    maxRange[i][j] = maxRange[i][j + 1] + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int minWidth = INT_MAX;
                for (int k = i; k < n; k++) {
                    minWidth = min(minWidth, maxRange[k][j]);                    
                    ans += minWidth;
                }                
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}