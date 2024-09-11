#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int bitsToFlip = start ^ goal, count = 0;        
        while(bitsToFlip) {
            count += bitsToFlip & 1;
            bitsToFlip >>= 1;
        }
        return count;
    }
};

int main() {
    return 0;
}