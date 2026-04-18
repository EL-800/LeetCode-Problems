#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int GetRev(int num) {
        int revNum = 0;
        while (num) {
            revNum *= 10;
            revNum += num % 10;
            num /= 10;
        }
        return revNum;
    }

public:
    int mirrorDistance(int n) {
        return abs(n - GetRev(n));
    }
};

int main() {
    return 0;
}