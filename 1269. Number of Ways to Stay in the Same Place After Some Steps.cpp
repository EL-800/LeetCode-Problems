#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int mod = int(1e9) + 7;
    int steps, arrLen;
    int FindWays(vector<vector<int>>& dp, int currS = 0, int currI = 0){
        if (currI < 0 || currI >= arrLen)
            return 0;
        if (currS == steps)
            return currI == 0;
        if (dp[currS][currI] != -1)
            return dp[currS][currI];        
        return dp[currS][currI] = ((FindWays(dp, currS + 1, currI + 1) % mod + FindWays(dp, currS + 1, currI - 1) % mod) % mod
            + FindWays(dp, currS + 1, currI) % mod) % mod;
    }

public:
    int numWays(int steps, int arrLen) {
        this->steps = steps;
        this->arrLen = arrLen;
        vector<vector<int>> dp(steps, vector<int>(steps, -1));
        return FindWays(dp);
    }
};

int main(){
    return 0;
}