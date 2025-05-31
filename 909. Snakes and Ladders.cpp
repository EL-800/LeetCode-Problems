#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> linearBoard;
        bool even = true;
        for (int i = n - 1; i >= 0; i--) {
            if (even)
                linearBoard.insert(linearBoard.end(), board[i].begin(), board[i].end());
            else
                linearBoard.insert(linearBoard.end(), board[i].rbegin(), board[i].rend());
            even = !even;
        }
        n = n * n;
        int dice = 6;
        queue<int> pendingMoves;
        vector<int> visited(n, -1);
        pendingMoves.push(0);
        visited[0] = 0;         
        while (!pendingMoves.empty()) {
            int curr = pendingMoves.front();            
            pendingMoves.pop();
            for (int i = 1; i <= dice && curr + i < n; i++) {
                int next = linearBoard[curr + i] == -1 ? curr + i : linearBoard[curr + i] - 1;
                if (visited[next] != -1)
                    continue;
                visited[next] = visited[curr] + 1;
                pendingMoves.push(next);                
            }            
        }
        return visited[n - 1];
    }
};

int main() {
    return 0;
}