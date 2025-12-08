#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int i = 2; i <= sqrt(n); i++) {
            for (int j = 1; j < i; j++) {
                if (__gcd(i, j) != 1 || i % 2 == j % 2)
                    continue;
                int c = i * i + j * j;
                if (c > n)
                    continue;            
                ans += (n / c) * 2;
            }            
        }
        return ans;
    }
};

int main() {
    return 0;
}