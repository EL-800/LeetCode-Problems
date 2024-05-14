#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0},{0, -1}};

    int GetMax(vector<vector<int>>& grid, int row, int col){
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
            return 0;
        if (!grid[row][col])        
            return 0;
        int originalValue = grid[row][col], maxValue = 0;
        grid[row][col] = 0;
        for (pair<int, int> move : moves)
            maxValue = max(GetMax(grid, row + move.first, col + move.second), maxValue);
        grid[row][col] = originalValue;
        return maxValue + originalValue;        
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxValue = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                maxValue = max(maxValue, GetMax(grid, i, j));
            }
        }
        return maxValue;
    }
};

int main(){
    return 0;
}