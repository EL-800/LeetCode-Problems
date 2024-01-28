#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
const int mod =(int)1e9 + 7;
    const vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int dp(vector<vector<vector<int>>>& memo, int m, int n, int currRow, int currCol, int currMove){
        if (currRow < 0 || currRow >= m || currCol < 0 || currCol >= n)
            return 1;
        if (!currMove)
            return 0;
        if (memo[currRow][currCol][currMove] != -1)
            return memo[currRow][currCol][currMove];
        int currSum = 0;
        for (auto move : moves)
            currSum = (currSum + dp(memo, m, n, currRow + move.first, currCol + move.second, currMove - 1)) % mod;                
        return memo[currRow][currCol][currMove] = currSum % mod;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return dp(memo, m, n, startRow, startColumn, maxMove) % mod;
    }
};

int main(){
    Solution s;
    s.findPaths(3, 6, 8, 0, 4);
    return 0;
}