#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<vector<int>>> validSquares = {{{6, 1, 8},
                                                {7, 5, 3},
                                                {2, 9, 4}},
                                                
                                                {{8, 1, 6},
                                                {3, 5, 7},
                                                {4, 9, 2}},

                                                {{6, 7, 2},
                                                {1, 5, 9},
                                                {8, 3, 4}},

                                                {{8, 3, 4},
                                                {1, 5, 9},
                                                {6, 7, 2}},

                                                {{2, 7, 6},
                                                {9, 5, 1},
                                                {4, 3, 8}},

                                                {{4, 3, 8},
                                                {9, 5, 1},
                                                {2, 7, 6}},

                                                {{2, 9, 4},
                                                {7, 5, 3},
                                                {6, 1, 8}},


                                                {{4, 9, 2},
                                                {3, 5, 7},
                                                {8, 1, 6}}
                                                };

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), ans = 0;
        if (rows < 3 || cols < 3)
            return 0;        
        for (int pivotRow = 1; pivotRow < rows - 1; pivotRow++) {
            for (int pivotCol = 1; pivotCol < cols - 1; pivotCol++) {
                vector<vector<int>> currSquare;
                for (int i = pivotRow - 1; i <= pivotRow + 1; i++) {
                    vector<int> row;
                    for (int j = pivotCol - 1; j <= pivotCol + 1; j++)
                        row.push_back(grid[i][j]);
                    currSquare.push_back(row);
                }
                for (auto square : validSquares)
                    ans += currSquare == square;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}