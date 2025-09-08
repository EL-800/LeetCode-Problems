#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool HasZeros(int n) {
        while (n) {
            if (!(n % 10)) 
                return true;
            n /= 10;
        }
        return false;
    }    
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= n; i++) {
            if (!HasZeros(n - i) && !HasZeros(i))
                return {i, n - i};
        }
        return {-1, -1};
    }
};

int main() {
    return 0;
}