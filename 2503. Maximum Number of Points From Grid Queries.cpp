#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            vector<pair<int, int>> indexedQueries;
            for (int i = 0; i < queries.size(); i++) 
                indexedQueries.emplace_back(queries[i], i);            
            sort(indexedQueries.begin(), indexedQueries.end());

            vector<int> ans(queries.size());
            priority_queue<vector<int>, vector<vector<int>>, greater<>> pendingMoves;            
            vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size()));
            int visitedCount = 0;            
            pendingMoves.push({grid[0][0], 0, 0});
            grid[0][0] = INT_MAX;
            for (auto query : indexedQueries) {
                auto [limit, index] = query;
                while (!pendingMoves.empty()) {
                    auto top = pendingMoves.top();
                    int val = top[0], row = top[1], col = top[2];
                    if (val >= limit)
                        break;                                            
                    pendingMoves.pop();                    
                    visitedCount++;                    
                    for (auto [moveR, moveC] : moves) { 
                        int newR = row + moveR, newC = col + moveC;                    
                        if (newR < 0 || newR >= grid.size() || newC < 0 || newC >= grid[0].size())
                            continue;              
                        if (vis[newR][newC])
                            continue;                                      
                        pendingMoves.push({grid[newR][newC], newR, newC});
                        vis[newR][newC] = true;
                    }
                }
                ans[index] = visitedCount;
            }
            return ans;            
        }
    };

int main() {
    return 0;
}