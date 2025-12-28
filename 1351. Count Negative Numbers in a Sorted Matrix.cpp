#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), col = m - 1, ans = 0;
        for (int row = 0; row < n; row++) {
            for (; col >= 0 && grid[row][col] < 0; col--);
            ans += m - col - 1;
        }
        return ans;
    }
};

int main() {
    return 0;
}