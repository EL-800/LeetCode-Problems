#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<pair<int, int>> adjMoves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int n = grid.size(), m = grid[0].size(), p = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!grid[i][j])
                    continue;
                int adjDirt = 0;
                for (auto move : adjMoves){
                    int adjI = i + move.first, adjJ = j + move.second;
                    if (adjI < 0 || adjI >= n || adjJ < 0 || adjJ >= m)
                        continue;                    
                    adjDirt += grid[adjI][adjJ];
                }
                p += 4 - adjDirt;
            }
        }
        return p;
    }
};
int main(){
    return 0;
}