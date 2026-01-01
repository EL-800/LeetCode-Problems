#include <bits/stdc++.h>

using namespace std;

class Solution {
private: 
    int row, col;
    vector<vector<bool>> grid;

    bool FindAWay(int currRow, int currCol) {
        if (currRow < 0 || currRow >= row || currCol < 0 || currCol >= col)
            return false;
        if (grid[currRow][currCol])
            return false;
        grid[currRow][currCol] = true;
        if (currRow == row - 1)
            return true;
        return FindAWay(currRow + 1, currCol) || FindAWay(currRow, currCol + 1)
            || FindAWay(currRow - 1, currCol) || FindAWay(currRow, currCol - 1);
    }

    int BS(vector<vector<int>>& cells, int left, int right) {
        if (left == right)
            return left;
        int mid = (left + right) / 2 + 1;
        grid.assign(row, vector<bool>(col));
        for (int i = 0; i < mid; i++)
            grid[cells[i][0] - 1][cells[i][1] - 1] = true;
        bool ans = false;
        for (int i = 0; i < col && !ans; i++)
            ans = FindAWay(0, i);        
        if (ans)
            return BS(cells, mid, right);
        return BS(cells, left, mid - 1);
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {   
        this->row = row;
        this->col = col;        
        return BS(cells, 0, (int)cells.size());
    }
};

int main() {
    return 0;
}