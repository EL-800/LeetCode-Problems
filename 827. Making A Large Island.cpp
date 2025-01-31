#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, islandInd = 0;
    vector<vector<int>> visited;
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int DFS(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= n || col < 0 || col >= n)
            return 0;
        if (!grid[row][col])
            return 0;
        if (visited[row][col] != -1)
            return 0;
        visited[row][col] = islandInd;
        int size = 1;
        for (auto [moveR, moveC] : moves) {
            int adjR = row + moveR, adjC = col + moveC;
            size += DFS(grid, adjR, adjC);
        }
        return size;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        visited.assign(n, vector<int>(n, -1));
        unordered_map<int, int> islandSize;      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && visited[i][j] == -1) 
                    islandSize[islandInd++] = DFS(grid, i, j);                
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j])
                    continue;
                unordered_set<int> adjIslands;
                for (auto [moveR, moveC] : moves) {
                    int adjR = i + moveR, adjC = j + moveC;
                    if (adjR < 0 || adjR >= n || adjC < 0 || adjC >= n)            
                        continue;
                    adjIslands.insert(visited[adjR][adjC]);
                }     
                int newArea = 1;
                for (auto adj : adjIslands) 
                    newArea += islandSize[adj];                            
                ans = max(ans, newArea);
            }
        }
        return ans ? ans : n * n;  
    }
};

int main() {

}