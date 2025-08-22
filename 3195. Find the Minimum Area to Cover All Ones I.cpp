#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int left = INT_MAX, top = INT_MAX, right = 0, bottom = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    left = min(left, j);
                    top = min(top, i);
                    right = max(right, j);
                    bottom = max(bottom, i);
                }
            }
        }
        return (right - left + 1) * (bottom - top + 1);
    }
};

int main() {
    return 0;
}