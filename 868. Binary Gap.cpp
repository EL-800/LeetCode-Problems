#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int pos = 0, prev = -1, ans = 0;
        while (1 << pos <= n) {
            if (1 << pos & n && prev != -1) 
                ans = max(ans, pos - prev); 
            if (1 << pos & n)
                prev = pos;    
            pos++;                                       
        }

        return ans;
    }
};

int main() {
    return 0;
}