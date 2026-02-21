#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

        for (int i = left; i <= right; i++) {
            int bitCount = __builtin_popcount(i);
            ans += count(primes.begin(), primes.end(), bitCount);
        }

        return ans;
    }
};

int main() {
    return 0;
}