#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m, k;
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int DFS(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || col < 0) 
            return 0;
        if (row >= n || col >= m)
            return 0;
        if (!grid[row][col])
            return 0;        

        int curr = grid[row][col];
        grid[row][col] = 0;
        for (auto [moveR, moveC] : moves) {
            int adjR = row + moveR, adjC = col + moveC;
            curr = (curr + DFS(grid, adjR, adjC)) % k;
        }

        return curr % k;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size(), this->k = k;
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j])
                    ans += DFS(grid, i, j) == 0;            
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}