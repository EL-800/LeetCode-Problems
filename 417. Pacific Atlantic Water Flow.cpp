#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<int>> visiteds;
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void DFS(vector<vector<int>>& heights, int row, int col, int ind) {         
        if (visiteds[row][col] & (1 << ind))
            return;       
        visiteds[row][col] |= 1 << ind;
        for (auto [mRow, mCol] : moves) {
            int adjRow = row + mRow, adjCol = col + mCol;
            if (adjRow < 0 || adjCol < 0 || adjRow >= n || adjCol >= m)
                continue;
            if (heights[row][col] <= heights[adjRow][adjCol])
                DFS(heights, adjRow, adjCol, ind);
        }        
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        visiteds.assign(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            DFS(heights, i, 0, 0);
            DFS(heights, i, m - 1, 1);
        }

        for (int i = 0; i < m; i++) {
            DFS(heights, 0, i, 0);
            DFS(heights, n - 1, i, 1);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visiteds[i][j] == 3)
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}