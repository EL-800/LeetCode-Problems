#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int mod = 1e9 + 7;

    int dp(vector<vector<vector<int>>>& memo, int ind = 0, int consecutive = 0, int absent = 0){
        if (consecutive == 3)
            return 0;
        if (absent == 2)
            return 0;
        if (ind == memo.size())
            return 1;
        if (memo[ind][consecutive][absent] != -1)
            return memo[ind][consecutive][absent];
        int p = dp(memo, ind + 1, 0, absent) % mod;
        int l = dp(memo, ind + 1, consecutive + 1, absent) % mod;
        int a = dp(memo, ind + 1, 0, absent + 1) % mod;
        return memo[ind][consecutive][absent] = ((p + l) % mod + a) % mod; 
                                                                                                
    }

public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return dp(memo);
    }
};

int main(){
    return 0;
}