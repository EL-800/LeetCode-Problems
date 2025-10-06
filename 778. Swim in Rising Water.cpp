#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pendingMoves;
        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        pendingMoves.push({grid[0][0], 0, 0});
        while (!pendingMoves.empty()) {
            int val = pendingMoves.top()[0], row = pendingMoves.top()[1], col = pendingMoves.top()[2];
            pendingMoves.pop();

            if (row == n - 1 && col == n - 1)
                return val;
                        
            for (auto [mRow, mCol] : moves) {
                int adjRow = row + mRow, adjCol = col + mCol;
                if (adjRow < 0 || adjRow >= n || adjCol < 0 || adjCol >= n)
                    continue;
                if (grid[adjRow][adjCol] == -1)
                    continue;                
                pendingMoves.push({max(val, grid[adjRow][adjCol]), adjRow, adjCol});
                grid[adjRow][adjCol] = -1;
            }
        }

        return 800;
    }
};

int main() {
    return 0;
}