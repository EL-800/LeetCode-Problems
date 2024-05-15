#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vector<vector<int>> CalculateManhattanDistances(vector<vector<int>>& grid){
        int n = grid.size();
        vector<vector<int>> manhattanDistances(n, vector<int>(n, -1));
        queue<pair<int, int>> pending;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j]){
                    manhattanDistances[i][j] = 0;
                    pending.push({i, j});
                }
            }
        }
        while (!pending.empty()){
            auto curr = pending.front();
            pending.pop();
            for (auto move : moves){
                int adjRow = curr.first + move.first, adjCol = curr.second + move.second;
                if (adjRow < 0 || adjRow >= n || adjCol < 0 || adjCol >= n)
                    continue;
                if (manhattanDistances[adjRow][adjCol] != -1)
                    continue;
                manhattanDistances[adjRow][adjCol] = manhattanDistances[curr.first][curr.second] + 1;
                pending.push({adjRow, adjCol});
            }
        }
        return manhattanDistances;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> manhattanDistances = CalculateManhattanDistances(grid);        
        vector<vector<int>> minOnPath(n, vector<int>(n, -1));
        priority_queue<array<int, 3>> pending;
        pending.push({manhattanDistances[0][0], 0, 0});
        minOnPath[0][0] = manhattanDistances[0][0];
        while (!pending.empty()){
            auto curr = pending.top();
            pending.pop();
            if (curr[1] == n - 1 && curr[2] == n - 1)
                return minOnPath[curr[1]][curr[2]];
            for (auto move : moves){
                int adjRow = curr[1] + move.first, adjCol = curr[2] + move.second;
                if (adjRow < 0 || adjRow >= n || adjCol < 0 || adjCol >= n)
                    continue;
                if (minOnPath[adjRow][adjCol] != -1)
                    continue;
                minOnPath[adjRow][adjCol] = min(minOnPath[curr[1]][curr[2]], manhattanDistances[adjRow][adjCol]);
                pending.push({manhattanDistances[adjRow][adjCol], adjRow, adjCol});
            }
        }
        return -1;
    }
};

int main(){
    return 0;
}