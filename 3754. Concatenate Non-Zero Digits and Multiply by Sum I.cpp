#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0, sum = 0, ind = 1;
        while (n) {
            int digit = n % 10;
            n /= 10;
            if (!digit)
                continue;
            sum += digit;
            x += digit * ind;
            ind *= 10;
        }

        return (long long)x * (long long)sum;
    }
};

int main() {
    return 0;
}