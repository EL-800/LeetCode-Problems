#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int mod = 1e9 + 7;

    long long FastExp(long long a, long long b)
    {
        long long result = 1;
        while (b) {
            if (b & 1)
                result = (result * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return result;
    }

    long long CalculateCombination(int n, int r){
        if (r > n) 
            return 0;
        if (r == 0 || r == n) 
            return 1;
        long long ans = 1;
        for (int i = 1; i <= r; i++){
            ans = ans * (n - r + i) % mod;
            ans = ans * FastExp(i, mod - 2) % mod;
        }
        return (int)ans;
    }


public:
    int countGoodArrays(int n, int m, int k) {
        long long first = ((long long)m * FastExp(m - 1, n - k -1)) % mod;
        long long second = CalculateCombination(n - 1, k) % mod;
        return int(first * second % mod);
    }
};

int main() {
    return 0;
}