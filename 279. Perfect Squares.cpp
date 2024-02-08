#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    const int inf = 100000;
    vector<vector<int>> dp;

    int Search(int i = 1, int curr = 0) {
        if (i * i > n)
            return inf;
        if (curr == n)
            return 0;
        if (curr > n)
            return inf;        
        if (dp[i][curr])
            return dp[i][curr];
        return dp[i][curr] = min(Search(i, curr + i * i) + 1, Search(i + 1, curr));
    }

public:
    int numSquares(int n) {
        this->n = n;
        dp.assign((int)sqrt(n) + 5, vector<int>(n));
        if (n == 1)
            return 1;
        return Search();
    }
};

int main(){
    return 0;
}