#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int layers = min(n, m) / 2;

        for (int l = 0; l < layers; l++) {
            vector<int> flattened;
            int top = l, left = l;
            int bottom = n - l - 1, right = m - l - 1;

            for (int i = left; i < right; i++)
                flattened.push_back(grid[top][i]);
            for (int i = top; i < bottom; i++)
                flattened.push_back(grid[i][right]);
            for (int i = right; i > left; i--)
                flattened.push_back(grid[bottom][i]);
            for (int i = bottom; i > top; i--)
                flattened.push_back(grid[i][left]);

            int len = flattened.size();
            int rotations = k % len;
            rotate(flattened.begin(), flattened.begin() + rotations, flattened.end());

            int ind = 0;
            for (int i = left; i < right; i++)
                grid[top][i] = flattened[ind++];
            for (int i = top; i < bottom; i++)
                grid[i][right] = flattened[ind++];
            for (int i = right; i > left; i--)
                grid[bottom][i] = flattened[ind++];
            for (int i = bottom; i > top; i--)
                grid[i][left] = flattened[ind++];
        }
        
        return grid;
    }
};

int main() {
    return 0;
}