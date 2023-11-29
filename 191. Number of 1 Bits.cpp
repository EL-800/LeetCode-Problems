#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;     
        if (n == 0)
            return 0;
        while (n &= (n - 1))
            ans++;
        return ans + 1;
    }
};

int main(){
    return 0;
}