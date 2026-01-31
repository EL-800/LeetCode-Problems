#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = lower_bound(letters.begin(), letters.end(), target + 1);
        return it != letters.end() ? *it : letters.front();
    }
};

int main() {
    return 0;
}