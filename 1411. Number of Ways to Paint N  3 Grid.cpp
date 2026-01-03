#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int mod = 1e9 + 7;
    int n, m = 3;
    vector<vector<vector<vector<int>>>> memo;

    int DP(int ind = 0, int col1 = 3, int col2 = 3, int col3 = 3) {
        if (ind == n)
            return 1;
        if (memo[ind][col1][col2][col3] != -1)
            return memo[ind][col1][col2][col3] % mod;
        
        int best = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    if (i == j || j == k)
                        continue;
                    if (i == col1 || j == col2 || k == col3)
                        continue;
                    best = (best + DP(ind + 1, i, j, k)) % mod;
                }
            }
        }
        
        return memo[ind][col1][col2][col3] = best % mod;
    }

public:
    int numOfWays(int n) {
        this->n = n;
        memo.assign(n, vector<vector<vector<int>>>(m + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, -1))));
        return DP() % mod;
    }
};

int main() {
    return 0;
}