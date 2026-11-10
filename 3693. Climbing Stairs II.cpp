#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int inf = 1e9;
    int n;
    vector<int> memo;

    int DP(vector<int>& costs, int ind = 0) {
        if (ind == n)
            return 0;
        if (memo[ind] != -1)
            return memo[ind];

        int curr = inf;
        for (int j = ind + 1; j <= min(ind + 3, n); j++) 
            curr = min(curr, DP(costs, j) + costs[j] + (j - ind) * (j - ind));    
            
        return memo[ind] = curr;
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        this->n = n;
        costs.insert(costs.begin(), 0);
        memo.assign(n + 1, -1);
        return DP(costs);
    }
};

int main() {
    return 0;
}