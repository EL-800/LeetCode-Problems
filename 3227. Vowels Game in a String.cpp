#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                return true;
        }
        return false;
    }
};

int main() {
    return 0;
}