#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return __builtin_popcount(n) == 1 && n > 0;
    }
};

int main(){
    return 0;
}