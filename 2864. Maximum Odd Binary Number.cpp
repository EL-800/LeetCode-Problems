#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = count(s.begin(), s.end(), '1') - 1, zeros = s.length() - ones - 1;
        string ans;
        while (ones--)
            ans += '1';
        while (zeros--)
            ans += '0';
        return ans + '1';
    }
};

int main(){
    return 0;
}