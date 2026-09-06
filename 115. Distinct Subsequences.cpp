#include <bits/stdc++.h>

using namespace std;

class Solution {
private:  
    int n, m;
    vector<vector<int>> memo;

    int dp(string &s, string &t, int i = 0, int j = 0) {
        if(j == m) 
            return 1; 
        if(i == n) 
            return 0;               

        if(memo[i][j] != -1) 
            return memo[i][j];

        int take = 0;        
        if(s[i] == t[j])
            take = dp(s, t, i + 1, j + 1);        
        int notTake = dp(s, t, i + 1, j);        

        return memo[i][j] = take + notTake;
    }

public:
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        memo.assign(n, vector<int>(m, -1));
        return dp(s, t);
    }
};

int main() {
    return 0;
}