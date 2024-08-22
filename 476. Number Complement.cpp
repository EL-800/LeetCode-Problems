#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        long long mask = 1;
        long long lNum = num;
        while (mask <= lNum) {
            lNum ^= mask;
            mask <<= 1;
        }
        return lNum;
    }
};

int main() {
    return 0;
}