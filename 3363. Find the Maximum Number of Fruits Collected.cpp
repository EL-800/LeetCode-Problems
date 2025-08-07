#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> memo;

    int dp(vector<vector<int>> &fruits, vector<pair<int, int>> &moves, int row, int col, bool flag) {
        if (row < 0 || row >= n)
            return 0;
        if (col < 0 || col >= n)
            return 0;
        if (!flag && row >= col)
            return 0;
        if (flag && row <= col)
            return 0;
        if (memo[row][col] != -1)
            return memo[row][col];        
        for (auto &move: moves) 
            memo[row][col] = max(memo[row][col], fruits[row][col] + 
                dp(fruits, moves, row + move.first, col + move.second, flag));        
        return memo[row][col];
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int diagonal = 0;
        n = fruits.size();
        memo.assign(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            diagonal += fruits[i][i];
            fruits[i][i] = -1;
        }

        vector<pair<int, int>> movesP2 = {{1, -1}, {1, 0}, {1, 1}}, movesP3 = {{-1, 1}, {0, 1}, {1, 1}};
        return diagonal + dp(fruits, movesP2, 0, n - 1, false) + dp(fruits, movesP3, n - 1, 0, true);
    }
};

int main() {
    vector<vector<int>> f = {{1,2,3,4},{5,6,8,7},{9,10,11,12},{13,14,15,16}};
    Solution s;
    cout << s.maxCollectedFruits(f);
    return 0;
}