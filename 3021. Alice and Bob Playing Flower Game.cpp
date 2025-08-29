#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long lN = n, lM = m, pairsN = n / 2, pairsM = m / 2;
        return pairsN * (lM - pairsM) + pairsM * (lN - pairsN);
    }
};

int main() {
    return 0;
}