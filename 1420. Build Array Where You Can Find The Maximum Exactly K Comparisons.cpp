#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int mod = (int)1e9 + 7;
    int n, m, k;

    int CountWays(vector<vector<vector<int>>> &dp, int currInd = 0, int currMax = 0, int currK = 0){
        if (currInd == n)
            return currK == k;
        if (currK > k)
            return 0;
        if (dp[currInd][currMax][currK] != -1)
            return dp[currInd][currMax][currK];
        long long mult = ((long long)(CountWays(dp, currInd + 1, currMax, currK) % (long long)mod) * (long long)currMax) % (long long) mod; 
        int count = (int)mult;
        for (int i = currMax + 1; i <= m; i++)
            count = (count + (CountWays(dp, currInd + 1, i, currK + 1) % mod)) % mod;
        return dp[currInd][currMax][currK] = count % mod;        
    }

public:
    int numOfArrays(int n, int m, int k) {
        this->n = n;
        this->m = m;
        this->k = k;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        return CountWays(dp) % mod;
    }
};

int main(){
    Solution s;
    cout << s.numOfArrays(2, 3, 1);
    return 0;
}