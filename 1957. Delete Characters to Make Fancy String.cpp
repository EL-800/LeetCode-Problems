#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3)
            return s;
        string ans;
        ans.push_back(s[0]);
        ans.push_back(s[1]);
        for (int i = 2; i < s.length(); i++) {
            if (s[i - 1] == s[i] && s[i - 2] == s[i])
                continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};

int main() {
    return 0;
}