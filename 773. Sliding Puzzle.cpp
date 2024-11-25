#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    pair<int, int> FindZero(vector<vector<int>> &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (!board[i][j])
                    return {i, j};
            }
        }
        return {0, 0};
    }

public:    
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> obj = {{1,2,3},{4,5,0}};
        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        map<vector<vector<int>>, int> visited;
        queue<vector<vector<int>>> pendingMoves;        
        visited[board] = 0;
        pendingMoves.push(board);
        while (!pendingMoves.empty()) {
            auto currBoard = pendingMoves.front();
            pendingMoves.pop();
            if (currBoard == obj)
                return visited[currBoard];
            for (auto [moveR, moveC] : moves) {
                auto [r, c] = FindZero(currBoard);
                if (r + moveR < 0 || r + moveR >= currBoard.size() || c + moveC < 0 || c + moveC >= currBoard[0].size())
                    continue;
                int prevValue = visited[currBoard];
                swap(currBoard[r][c], currBoard[r + moveR][c + moveC]);
                if (!visited.count(currBoard)) {                    
                    pendingMoves.push(currBoard);
                    visited[currBoard] = prevValue + 1;                    
                }
                swap(currBoard[r][c], currBoard[r + moveR][c + moveC]);
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}