#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (right >= 0) {
            if (s[left] == s[right])
                left++;
            right--;
        }
        string remaining = s.substr(left), rev(remaining.rbegin(), remaining.rend());
        if (!remaining.length()) 
            return s;
        return rev + shortestPalindrome(s.substr(0, left)) + remaining;

    }
};

int main() {
    return 0;
}