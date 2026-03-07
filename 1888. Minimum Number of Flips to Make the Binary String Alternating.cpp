#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        vector<int> parityOp(2);

        for (int i = 0; i < n; i++)
            parityOp[(s[i] ^ i) & 1]++;

        int ans = min(parityOp[0], parityOp[1]);

        for (int i = 0; i < n - 1; i++) {
            parityOp[(s[i] ^ i) & 1]--;
            parityOp[(s[i] ^ (n + i)) & 1]++;
            ans = min(ans, min(parityOp[0], parityOp[1]));
        }

        return ans;
    }
};

int main() {
    return 0;
}