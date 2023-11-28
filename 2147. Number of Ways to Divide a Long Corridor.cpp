#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int mod = (int)1e9 + 7;
    int n;

    int dp(string& corridor, vector<vector<int>>& memo, int ind = 0, int numS = 0){
        if (ind == n)
            return numS == 2 ? 1 : 0;        
        if (memo[ind][numS] != - 1)
            return memo[ind][numS];
        int left = 0, right = 0;
        if (corridor[ind] == 'S')
            numS++;
        if (numS > 2)
            return 0;
        if (numS == 2)
            left = dp(corridor, memo, ind + 1, 0);
        right = dp(corridor, memo, ind + 1, numS);
        return memo[ind][numS] = (left + right) % mod;
    }

public:
    int numberOfWays(string corridor) {
        n = corridor.length();
        vector<vector<int>> memo(n, vector<int>(3, -1));
        return dp(corridor, memo) % mod;
    }
};

int main(){
    Solution s;
    cout << s.numberOfWays("SSPPSPS");
    return 0;
}