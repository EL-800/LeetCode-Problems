#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSub(string s) {
        int n = s.length(), currSize = 0, ans = 0, MOD = 1e9 + 7;        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') 
                currSize++;
            else
                currSize = 0;
            ans = (ans + currSize) % MOD;
        }        

        return ans;
    }
};

int main() {
    return 0;
}