#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length() - 2;        

        int digit1 = s[0] - '0', digit2 = s[1] - '0';;
        __int128_t coefficent = 1;
        for (int i = 1; i <= n; i++) {            
            coefficent = coefficent * (n - i + 1) / i;
            digit1 = (digit1 + (s[i] - '0') * coefficent % 10) % 10;
            digit2 = (digit2 + (s[i + 1] - '0') * coefficent % 10) % 10;            
        }                        
        
        return digit1 % 10 == digit2 % 10;
    }
};

int main() {
    return 0;
}