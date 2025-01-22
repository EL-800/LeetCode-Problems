#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>> heights(n, vector<int>(m, -1));
        queue<pair<int, int>> pendingMoves;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j]) {
                    heights[i][j] = 0;
                    pendingMoves.push({i, j});
                }
            }
        }
        while (!pendingMoves.empty()) {
            auto [row, col] = pendingMoves.front();
            pendingMoves.pop();
            for (auto [moveR, moveC] : moves) {
                int adjR = row + moveR, adjC = col + moveC;
                if (adjR < 0 || adjR >= n || adjC < 0 || adjC >= m || heights[adjR][adjC] != -1)
                    continue;                                
                heights[adjR][adjC] = heights[row][col] + 1;                
                pendingMoves.push({adjR, adjC});
            }
        }
        return heights;        
    }
};

int main() {
    return 0;
}