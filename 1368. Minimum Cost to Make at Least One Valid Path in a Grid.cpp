#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pendingMoves;
        vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> minimums(n, vector<int>(m, INT_MAX));
        minimums[0][0] = 0;
        pendingMoves.push({0, 0, 0});
        while (!pendingMoves.empty()) {
            int w = pendingMoves.top()[0], r = pendingMoves.top()[1], c = pendingMoves.top()[2];
            pendingMoves.pop();
            if (r == n - 1 && c == m - 1) 
                return w;                        
            for (int i = 0; i < moves.size(); i++) {
                int adjR = r + moves[i].first, adjC = c + moves[i].second;
                if (adjR < 0 || adjR >= n || adjC < 0 || adjC >= m)
                    continue;                                          
                int adjW = i + 1 == grid[r][c] ? w : w + 1;           
                if (minimums[adjR][adjC] > adjW) {
                    minimums[adjR][adjC] = adjW;
                    pendingMoves.push({adjW, adjR, adjC});
                }
            }                    
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> a = {{1,2},{4,3}};
    Solution s;
    s.minCost(a);
    return 0;
}