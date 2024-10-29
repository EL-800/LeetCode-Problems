#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<int>> memo;
    vector<pair<int, int>> moves = {{1, 1}, {0, 1}, {-1, 1}};

    int DP(vector<vector<int>> &grid, int y, int x) {                    
        if (memo[y][x])
            return memo[y][x];
        for (auto [moveY, moveX] : moves) {
            int adjY = y + moveY, adjX = x + moveX;
            if (adjY < 0 || adjY >= n || adjX < 0 || adjX >= m)
                continue;
            if (grid[y][x] >= grid[adjY][adjX])
                continue;
            memo[y][x] = max(memo[y][x], DP(grid, adjY, adjX) + 1);
        }
        return memo[y][x];
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();        
        memo.assign(n, vector<int>(m));
        int ans = 0;
        for (int i = 0; i < n; i++) 
            ans = max(ans, DP(grid, i, 0));                
        return ans;
    }
};

int main() {
    vector<vector<int>> c = {{2,4,3,5},{5,4,9,3},{3,4,2,11},{10,9,13,15}};
    Solution s;
    cout << s.maxMoves(c);
    return 0;
}