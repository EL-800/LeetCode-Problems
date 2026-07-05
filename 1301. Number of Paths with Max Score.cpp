#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int mod = 1e9 + 7;
    int n;
    int maxPathMemo[101][101];
    int countPathMemo[101][101][1801];    
    vector<pair<int, int>> moves = {{-1, 0}, {0, -1}, {-1, -1}};

    int MaxPathDP(vector<string>& board, int row, int col) {
        if (row < 0 || row >= n)
            return INT_MIN;
        if (col < 0 || col >= n)
            return INT_MIN;
        if (board[row][col] == 'X')
            return INT_MIN;
        if (board[row][col] == 'E')
            return 0;
        if (maxPathMemo[row][col] != -1)
            return maxPathMemo[row][col];
        
        maxPathMemo[row][col] = 0;
        for (auto &[moveR, moveC] : moves) 
            maxPathMemo[row][col] = max(maxPathMemo[row][col], 
                MaxPathDP(board, row + moveR, col + moveC) + board[row][col] - '0');   
            
        return maxPathMemo[row][col];
    }

    int CountPathDP(vector<string>& board, int row, int col, int sum) {
        if (row < 0 || row >= n)
            return 0;
        if (col < 0 || col >= n)
            return 0;
        if (board[row][col] == 'X')
            return 0;
        if (sum < 0)
            return 0;
        if (board[row][col] == 'E') {
            return sum == 0;     
        }
        if (countPathMemo[row][col][sum] != -1) 
            return countPathMemo[row][col][sum];
        
        countPathMemo[row][col][sum] = 0;
        for (auto &[moveR, moveC] : moves) 
            countPathMemo[row][col][sum] = (countPathMemo[row][col][sum] + CountPathDP(board, row + moveR, col + moveC, sum - (board[row][col] - '0'))) % mod;

        return countPathMemo[row][col][sum] % mod;
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        memset(maxPathMemo, -1, sizeof(maxPathMemo));
        memset(countPathMemo, -1, sizeof(countPathMemo));
        board[n - 1][n - 1] = '0';
        int maxPath = MaxPathDP(board, n - 1, n - 1);        
        int countPath = CountPathDP(board, n - 1, n - 1, maxPath);
        return {countPath == 0 ? 0 : maxPath, countPath};
    }
};

int main() {
    return 0;
}