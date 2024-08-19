#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int cb = 0, size = 1, op = 0;        
        while(size < n) {
            if ((n - size) % size == 0) {
                cb = size;
                op++;
            }
            size += cb;
            op++;
        }
        return op;
    }
};

int main() {
    Solution s;
    cout << s.minSteps(7);
    return 0;
}