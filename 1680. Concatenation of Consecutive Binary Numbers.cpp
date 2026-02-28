#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int mod = 1000000007;
public:
    int concatenatedBinary(int n) {
        if (n == 1)
            return 1;
        int curr = concatenatedBinary(n - 1), i = 0;
        while (1 << i <= n) {
            curr = (curr << 1) % mod;
            i++;
        }
        return (curr + n) % mod;
    }
};

int main() {
    return 0;
}