#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int ind2 = 0;
        for (int ind1 = 0; ind1 < str1.length() && ind2 < str2.length(); ind1++) {
            int val1 = str1[ind1] - 'a', val2 = str2[ind2] - 'a';
            if (val1 == val2 || (val1 + 1) % 26 == val2)
                ind2++;

        }
        return ind2 == str2.length();
    }
};

int main() {
    return 0;
}