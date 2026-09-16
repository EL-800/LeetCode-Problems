#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int mod = 1e9 + 7;
    int n;
    int memo[1002][1002][2];

    int dp(int ind, int remainingLines, int puttingLine) {
        if (remainingLines == 0)
            return 1;
        if (ind == n) 
            return 0;        
        if (memo[ind][remainingLines][puttingLine] != -1) 
            return memo[ind][remainingLines][puttingLine];        

        if (puttingLine) {
            int keepGoing = dp(ind + 1, remainingLines, true) % mod;
            int stop = dp(ind, remainingLines - 1, false) % mod;
            return memo[ind][remainingLines][puttingLine] = (keepGoing + stop) % mod;
        }

        int notTake = dp(ind + 1, remainingLines, false) % mod;
        int take = dp(ind + 1, remainingLines, true) % mod;
        return memo[ind][remainingLines][puttingLine] = (notTake + take) % mod;
    }

public:
    int numberOfSets(int n, int k) {
        this->n = n;
        memset(memo, -1, sizeof(memo));
        return dp(0, k, false);
    }
};

int main() {
    return 0;
}