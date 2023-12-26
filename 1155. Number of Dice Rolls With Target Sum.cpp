#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int mod = (int)pow(10, 9) + 7;
    int n, k, target;
    vector<vector<int>> dp;

    int FindTargets(int i = 0, int curr = 0) {
        if (i == n && curr == target) 
            return 1;
        if (i == n)
            return 0;
        if (curr >= target)
            return 0;
        if (dp[i][curr] != -1)
            return dp[i][curr];
        dp[i][curr] = 0;
        for (int j = 1; j <= k; j++)
            dp[i][curr] = (dp[i][curr] % mod + FindTargets(i + 1, curr + j) % mod) % mod;
        return dp[i][curr] % mod;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        this->n = n;
        this->k = k;
        this->target = target;
        dp.assign(n, vector<int>(target, -1));
        return FindTargets();
    }
};

int main(){
    return 0;
}