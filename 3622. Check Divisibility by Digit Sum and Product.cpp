#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n, sum = 0, mult = 1;
        while (n) {
            int digit = n % 10;
            sum += digit;
            mult *= digit;
            n /= 10;            
        }

        return num % (sum + mult) == 0; 
    }
};

int main() {
    return 0;
}