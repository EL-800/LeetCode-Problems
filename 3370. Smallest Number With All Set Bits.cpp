#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1;
        while (ans <= n)
            ans <<= 1;
        return ans - 1;
    }
};

int main() {
    return 0;
}