#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {                                
        int n = s.length(), ones = count(s.begin(), s.end(), '1'), currNum = 0, currExp = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                currNum += currExp;
                if (currNum > k)
                    break;
                ones--;                 
            }
            currExp <<= 1;
            if (currExp > k)                
                break;
        }
        return n - ones;
    }
};

int main() {
    return 0;
}