#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int inf = 100000;
    int n, d;
    vector<int> jobDifficulty;
    vector<vector<int>> dp;

    int FindMin(int i = 0, int currD = 0) {
        if (currD == d && i == n)
            return 0;            
        if (currD == d)
            return inf;
        if (dp[i][currD] != -1)
            return dp[i][currD];   
        int curr = -1, ans = inf;
        for (int j = i; j < n; j++) {
            curr = max(curr, jobDifficulty[j]);
            ans = min(ans, curr + FindMin(j + 1, currD + 1));
        }
        return dp[i][currD] = ans;
    }

public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        this->n = jobDifficulty.size();
        this->d = d;
        this->jobDifficulty = jobDifficulty;
        dp.assign(n + 1, vector<int>(d + 1, -1));        
        int ans = FindMin();
        return ans != inf ? ans : -1;
    }
};

int main(){

}