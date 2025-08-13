#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        int biggetPow = 1162261467;        
        return n > 0 && !(biggetPow % n);
    }
};

int main() {
    return 0;
}