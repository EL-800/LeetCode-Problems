#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
        bool turn = false;
        while (n - remove >= 0) {
            n -= remove;
            remove--;
            turn = !turn;
        }

        return turn;
    }
};

int main() {
    return 0;
}