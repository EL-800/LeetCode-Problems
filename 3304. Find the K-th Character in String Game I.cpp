#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + __builtin_popcount(k - 1);
    }
};

int main() {
    return 0;
}