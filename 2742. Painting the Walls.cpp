#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    int FindMin(vector<unordered_map<int, int>>& dp, vector<int>& cost, vector<int>& time, int i = 0, int t = 0){
        if (i == n)
            return t >= 0 ? 0 : 1000000000;
        if (dp[i].count(t))
            return dp[i][t];
        return dp[i][t] = min(FindMin(dp, cost, time, i + 1, t - 1), 
            FindMin(dp, cost, time, i + 1, min(t + time[i], 500)) + cost[i]);
    }

public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        vector<unordered_map<int, int>> dp(n);
        return FindMin(dp, cost, time);
    }
};

int main(){
    vector<int> a = {1,2,3,2};
    vector<int> b = {1,2,3,2};
    Solution s;
    cout << s.paintWalls(a, b);
    return 0;
}