#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, x, mod = 1e9 + 7;;
    vector<vector<int>> memo;

    int dp(int currNum = 0, int sumInd = 1) {
        int p = x, sum = 1;
        while (p--) 
            sum *= sumInd;                
        if (currNum == n)
            return 1;
        if (currNum > n || sum > n)
            return 0;                
        if (memo[currNum][sumInd] != -1)
            return memo[currNum][sumInd];
        return memo[currNum][sumInd] = (dp(currNum, sumInd + 1) + dp(currNum + sum, sumInd + 1)) % mod;
    }

public:
    int numberOfWays(int n, int x) {
        this->n = n;
        this->x = x;
        memo.assign(n, vector<int>(n + 1, -1));
        return dp();
    }
};

int main() {
    return 0;
}