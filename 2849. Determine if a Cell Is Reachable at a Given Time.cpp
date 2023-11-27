#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy)
        return t == 1 ? false : true;
        int chevDis = max(abs(sx - fx), abs(sy - fy));
        return chevDis <= t;
    }
};

int main(){
    return 0;
}