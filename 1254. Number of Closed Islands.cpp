#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool IsClosed(vector<vector<int>>& grid, int y, int x) {
        if (y < 0 || y >= (int)grid.size() || x < 0 || x >= (int)grid[0].size())
            return false;
        if (grid[y][x])
            return true;
        grid[y][x] = 1;
        bool up = IsClosed(grid, y + 1, x);
        bool down = IsClosed(grid, y - 1, x);
        bool right = IsClosed(grid, y, x + 1);
        bool left = IsClosed(grid, y, x - 1);
        return up && down && right && left;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < (int)grid.size(); i++) {
            for (int j = 0; j < (int)grid[0].size(); j++) {
                if (!grid[i][j] && IsClosed(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}