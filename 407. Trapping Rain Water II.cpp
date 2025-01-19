#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pendingMoves;   
        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};     
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    pendingMoves.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }        
        int ans = 0, currentMax = 0;        
        while (!pendingMoves.empty()) {            
            int h = pendingMoves.top()[0], row = pendingMoves.top()[1], col = pendingMoves.top()[2];            
            pendingMoves.pop();
            currentMax = max(currentMax, h);
            for (auto move : moves) {
                int adjRow = row + move.first, adjCol = col + move.second;
                if (adjRow < 0 || adjRow >= n || adjCol < 0 || adjCol >= m)
                    continue;
                if (visited[adjRow][adjCol])
                    continue;
                visited[adjRow][adjCol] = true;                
                ans += max(currentMax - heightMap[adjRow][adjCol], 0);                    
                pendingMoves.push({max(heightMap[adjRow][adjCol], currentMax), adjRow, adjCol});                
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}