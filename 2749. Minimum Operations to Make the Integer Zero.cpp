#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long lNum1 = num1, lNum2 = num2;
        for (long long i = 1; i <= 60; i++) {
            long long x = lNum1 - lNum2 * i ;
            if (i > x)
                return -1;
            if (i >= __builtin_popcountll(x))
                return i; 
        }
        return -1;
    }
};

int main() {
    return 0;
}