#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string processStr(string s) {
        string ans;

        for (char c : s) {
            if (c == '*') {
                if (ans.empty())
                    continue;
                ans.pop_back();
            }
            else if (c == '#')
                ans.insert(ans.end(), ans.begin(), ans.end());
            else if (c == '%')
                reverse(ans.begin(), ans.end());
            else 
                ans.push_back(c);
        }

        return ans;
    }
};

int main() {
    return 0;
}