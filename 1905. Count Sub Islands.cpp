#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col) {
        if (row < 0 || row >= grid1.size() || col < 0 || col >= grid1[0].size())
            return true;        
        if (!grid2[row][col])
            return true;
        grid2[row][col] = false;            
        bool ans = grid1[row][col];
        for (auto [mR, mC] : moves)
            ans &= DFS(grid1, grid2, row + mR, col + mC);
        return ans;
    }   

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        for (int i = 0; i < grid1.size(); i++) {
            for (int j = 0; j < grid1[0].size(); j++) {
                if (grid2[i][j])
                    ans += DFS(grid1, grid2, i, j);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}