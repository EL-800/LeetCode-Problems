#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bitsCount = 0;
        while (num2) {
            bitsCount += num2 & 1;
            num2 >>= 1;
        }
        int currBit = 1;
        while (currBit <= num1)
            currBit <<= 1;
        currBit >>= 1;
        int ans = 0;
        while (bitsCount && currBit) {
            if (currBit & num1) {
                bitsCount--;
                ans |= currBit; 
            }
            currBit >>= 1;
        }
        currBit = 1;
        while (bitsCount) {
            if (!(currBit & num1)) {
                bitsCount--;
                ans |= currBit;
            }
            currBit <<= 1;
        }
        return ans;
    }
};

int main() {
    return 0;
}