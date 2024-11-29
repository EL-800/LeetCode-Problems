#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {        
        int n = grid.size(), m = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pendingMoves;
        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        if (grid[1][0] > 1 && grid[0][1] > 1)
            return -1;
        pendingMoves.push({0, 0, 0});
        grid[0][0] = -1;
        while (!pendingMoves.empty()) {
            auto curr = pendingMoves.top();
            pendingMoves.pop();
            int val = curr[0], row = curr[1], col = curr[2];
            if (row == n - 1 && col == m - 1)
                return val;
            for (auto [mR, mC] : moves) {
                if (row + mR < 0 || row + mR >= n || col + mC < 0 || col + mC >= m)
                    continue;
                if (grid[row + mR][col + mC] == -1)
                    continue;
                int add = max(grid[row + mR][col + mC] - val, 1);
                if (!(add % 2))
                    add++;  
                pendingMoves.push({val + add, row + mR, col + mC});
                grid[row + mR][col + mC] = -1;              
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}