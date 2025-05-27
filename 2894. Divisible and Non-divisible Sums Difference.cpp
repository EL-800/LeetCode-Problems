#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int div = n / m, sum2 = m * ((div * (div + 1)) / 2), sum1 = n * (n + 1) / 2 - sum2;
        return sum1 - sum2;        
    }
};

int main() {
    return 0;
}