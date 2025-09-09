#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod = 1e9 + 7;
        vector<int> memo(n);
        memo[0] = 1;
        long long curr = 0, ans = 0;
        for (int i = delay; i < n; i++) {
            curr += memo[i - delay] - (i - forget >= 0 ? memo[i - forget] : 0);
            memo[i] = (curr + mod) % mod;        
            ans += (i >= n - forget ? curr : 0);    
        }
        ans += forget == n;
        return ans % mod;    
    }
};

int main() {
    return 0;
}