#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;

    vector<pair<int, int>> adjMoves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void DFS(vector<vector<int>>& land, int row, int col, int &maxRow, int &maxCol){
        pair<int, int> endPosition = {0, 0};
        if (row < 0 || row >= n || col < 0 || col >= m)
            return;
        if (!land[row][col])
            return;
        maxRow = max(maxRow, row);
        maxCol = max(maxCol, col);
        land[row][col] = 0;
        for (auto move : adjMoves)
            DFS(land, row + move.first, col + move.second, maxRow, maxCol);                            
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size();
        m = land[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (land[i][j]){
                    int endRow = 0, endCol = 0;
                    DFS(land, i, j, endRow, endCol);
                    ans.push_back({i, j, endRow, endCol});
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> a = {{1,0,0},{0,1,1},{0,1,1}};
    Solution s;
    s.findFarmland(a);
    return 0;
}