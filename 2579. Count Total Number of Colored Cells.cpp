#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long coloredCells(int n) {
            long long lN = n;            
            return 4 * lN * (lN - 1) / 2 + 1;
        }
    };

int main() {
    return 0;
}