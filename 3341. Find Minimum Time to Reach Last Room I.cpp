#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int n = moveTime.size(), m = moveTime[0].size();
            vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            priority_queue<vector<int>, vector<vector<int>>, greater<>> pendingMoves;
            pendingMoves.push({0, 0, 0});
            moveTime[0][0] = -1;
            while (!pendingMoves.empty()) {
                int row = pendingMoves.top()[1], col = pendingMoves.top()[2], val = pendingMoves.top()[0];
                pendingMoves.pop();
                if (row == n - 1 && col == m -1)
                    return val;
                for (auto [moveR, moveC] : moves) {
                    int adjR = row + moveR, adjC = col + moveC;
                    if (adjR >= n || adjC >= m || adjR < 0 || adjC < 0)
                        continue;
                    if (moveTime[adjR][adjC] == -1)
                        continue;
                    pendingMoves.push({max(moveTime[adjR][adjC] + 1, val + 1), adjR, adjC});  
                    moveTime[adjR][adjC] = -1;                                      
                }
            }
            return -1;
        }
    };

int main() {
    return 0;
}