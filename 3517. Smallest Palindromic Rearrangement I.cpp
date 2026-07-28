#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string ans = s.substr(0, n / 2);        
        sort(ans.begin(), ans.end());
        if (n % 2) {
            ans.push_back(s[n / 2]);
            ans.insert(ans.end(), next(ans.rbegin()), ans.rend());
        }
        else 
            ans.insert(ans.end(), ans.rbegin(), ans.rend());
        return ans;
    }
};

int main() {
    return 0;
}