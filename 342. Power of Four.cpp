#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        int mask = 1431655765;
        if (n > 0 && (n & (n - 1)) == 0 && (n & mask) != 0)
            return true;
        return false;
    }
};

int main(){
    return 0;
}