#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int GetProduct(int n) {
        int p = 1;
        while (n) {
            p *= n % 10;
            n /= 10;
        }

        return p;
    }

public:
    int smallestNumber(int n, int t) {
        while (GetProduct(n) % t != 0)
            n++;
        return n;
    }
};

int main() {
    return 0;
}