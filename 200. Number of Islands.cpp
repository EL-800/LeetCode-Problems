#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<pair<int, int>> moves = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

    void DFS(vector<vector<char>>& grid, int y, int x) {
        if (y < 0 || x < 0 || y >= (int)grid.size() || x >= (int)grid[0].size())
            return;
        if (grid[y][x] == '0')
            return;
        grid[y][x] = '0'; //Marcamos visitados
        for (auto currMove : moves)
            DFS(grid, y + currMove.first, x + currMove.second);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < (int)grid.size(); i++) {
            for (int j = 0; j < (int)grid[i].size(); j++) {                
                if (grid[i][j] == '1') {
                    DFS(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}