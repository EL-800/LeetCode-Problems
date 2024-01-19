#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int dp(int n, vector<int> &memo, int ind = 0){
        if (ind > n)
            return 0;
        if (ind == n)
            return 1;
        if (memo[ind] != -1)
            return memo[ind];
        return memo[ind] = dp(n, memo, ind + 1) + dp(n, memo, ind + 2);
    }

public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return dp(n, memo);
    }
};

int main(){
    return 0;
}