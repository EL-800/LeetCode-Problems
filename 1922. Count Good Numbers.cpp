#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        const int mod = 1e9 + 7;

        long long GetModuledPower(long long x, long long n) {
            long long result = 1;
            while(n > 0) {
                if(n % 2) 
                    result = (result * x) % mod;                
                x = (x * x) % mod;
                n >>= 1; 
            }
            return result;
        }

    public:
        int countGoodNumbers(long long n) {
            long long ans = GetModuledPower(5, n / 2 + (n % 2)) * GetModuledPower(4, n / 2);
            return int(ans % mod);
        }
    };

int main() {
    return 0;
}