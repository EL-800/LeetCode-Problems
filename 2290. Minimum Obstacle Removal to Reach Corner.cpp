#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {        
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};        
        priority_queue<vector<int>, vector<vector<int>>, less<vector<int>>> pendingMoves;
        pendingMoves.push({0, 0, 0});
        grid[0][0] = 2;
        while (!pendingMoves.empty()) {
            auto curr = pendingMoves.top();
            int val = curr[0], row = curr[1], col = curr[2];
            pendingMoves.pop();
            if (row == n - 1 && col == m - 1)
                return val;
            for (auto [mR, mC] : moves) {
                if (row + mR < 0 || row + mR >= n || col + mC < 0 || col + mC >= m)
                    continue;
                if (grid[row + mR][col + mC] == 2)
                    continue;
                grid[row + mR][col + mC] = 2;
                pendingMoves.push({val + grid[row + mR][col + mC], row + mR, col + mC});
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}