#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int n = s.length(), onesCount = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && (!i || s[i - 1] != s[i])) 
                ans += onesCount;            
            else if (s[i] == '1')
                onesCount++;
        }

        return ans;
    }
};

int main() {
    return 0;
}