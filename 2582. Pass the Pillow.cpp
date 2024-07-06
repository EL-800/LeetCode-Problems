#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int completeCycle = time % ((n - 1) * 2);
        return completeCycle < n ? completeCycle + 1 : n - completeCycle % n + 1;        
    }
};

int main() {
    return 0;
}