#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int SearchMin(vector<int>& cost, vector<int>& dp, int ind){
        if (ind >= cost.size())
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        return dp[ind] = min(SearchMin(cost, dp, ind + 1), SearchMin(cost, dp, ind + 2)) + cost[ind];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(SearchMin(cost, dp, 0), SearchMin(cost, dp, 1));
    }
};

int main(){
    return 0;
}