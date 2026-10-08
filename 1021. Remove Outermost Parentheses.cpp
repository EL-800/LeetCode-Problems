#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int opens = 0;
        string ans;
        for (char c : s) {
            if (c == ')')
                opens--;
            if (opens)
                ans.push_back(c);
            if (c == '(')
                opens++;            
        }

        return ans;
    }
};

int main() {
    return 0;
}