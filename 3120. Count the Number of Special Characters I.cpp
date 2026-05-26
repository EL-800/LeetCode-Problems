#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lowerMask = 0, upperMask = 0;        

        for (char c : word) {
            if (islower(c))
                lowerMask |= 1 << (c - 'a');
            else    
                upperMask |= 1 << (c - 'A');
        }

        int repeateds = lowerMask & upperMask;
        
        return __builtin_popcount(repeateds);
    }
};

int main() {
    return 0;
}