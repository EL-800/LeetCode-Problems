#include <bits/stdc++.h>

using namespace std;

class Solution {
private:    
    const int height = 4, width = 3, mod = (int)1e9 + 7;
    int n;
    vector<pair<int, int>> moves = {{2, 1},{-2, 1},{2, -1}, {-2, -1},{1,2},{-1,2},{1,-2},{-1,-2}};
    vector<pair<int, int>> invalidCells = {{3, 0}, {3, 2}};

    int Count(vector<vector<vector<int>>>& dp, int row, int col, int move = 1){
        if (row < 0 || row >= height || col < 0 || col >= width)
            return 0;
        if (count(invalidCells.begin(), invalidCells.end(), make_pair(row, col)))
            return 0;
        if (move == n)
            return 1;
        if (dp[row][col][move] != -1)
            return dp[row][col][move];
        int ways = 0;
        for (auto nextMove : moves)
            ways = (ways + Count(dp, row + nextMove.first, col + nextMove.second, move + 1)) % mod;
        return dp[row][col][move] = ways % mod;              
    }

public:
    int knightDialer(int n) {        
        this->n = n;
        vector<vector<vector<int>>> dp(height, vector<vector<int>>(width, vector<int>(n, -1)));
        int ans = 0;
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++)
                ans = (ans + Count(dp, i, j)) % mod;
        }
        return ans;
    }
};

int main(){
    return 0;
}