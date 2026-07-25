#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int firstMax = 0, secondMax = 0;

        while (n) {
            int digit = n % 10;
            if (digit > firstMax) {
                secondMax = firstMax;
                firstMax = digit;
            }
            else if (digit > secondMax)
                secondMax = digit;
            n /= 10;
        }

        return firstMax * secondMax;
    }
};

int main() {
    return 0;
}