#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int> changes;   
        long long xl = x;                  
        for(int i = 0; i < 64; i++) {
            if(!(((long long)1 << i) & xl))
                changes.push_back(i);
        }        
        long long calc = n - 1, ans = x;
        for(int i = 0; calc > 0; i++, calc >>= 1)
            ans += (calc & 1) << changes[i];        
        return ans;
    }
};

int main() {
    return 0;
}