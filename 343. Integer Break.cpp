#include <bits/stdc++.h>

using namespace std;

class SolutionDP {
private:
    int FindMax(vector<int> &dp, int n){
        if (n < 0)
            return 0;
        if (!n)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int best = 0;
        for (int i = 1; i <= n; i++)
            best = max(best, FindMax(dp, n - i) * i);
        return dp[n] = best;
    }
public:
    int integerBreak(int n) {   
        if (n <= 3)
            return n - 1;     
        vector<int> dp(n + 1, -1);                
        return FindMax(dp, n);
    }
};

class SolutionMath {
public:
    int integerBreak(int n) {   
        if (n <= 3)
            return n - 1;     
        int ans = 1;
        while (n > 4){
            n -= 3;
            ans *= 3;
        }
        return ans * n;
    }
};



int main(){
    return 0;
}