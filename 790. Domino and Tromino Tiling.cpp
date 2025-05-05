#include <bits/stdc++.h>

using namespace std;

class Solution {    
    private:
    const long mod = 1e9 + 7;
        int n;
        vector<long> memo;
        
        long dp(int ind = 0) {  
            if (ind == n)
                return 1;          
            if (ind > n)
                return 0;
            if (memo[ind] != -1)
                return memo[ind];
            long vertical = dp(ind + 1), horizontal = dp(ind + 2), tromino = 0;
            for (int i = ind + 3; i <= n; i++)
                tromino = (tromino + 2 * dp(i)) % mod;                        
            return memo[ind] = (vertical + horizontal + tromino) % mod;
        }

    public:
        int numTilings(int n) {
            this->n = n;
            memo.assign(n + 1, -1);
            return dp() % mod;
        }
    };

int main() {
    return 0;
}