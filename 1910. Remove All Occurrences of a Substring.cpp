#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string removeOccurrences(string s, string part) {
            int n = part.size();
            string ans;
            for (char c : s) {
                ans.push_back(c);
                if (ans.size() >= n && ans.substr(ans.size() - n) == part)
                    ans.erase(ans.size() - n, n);                 
            }
            return ans;
        } 
    };

int main() {
    return 0;
}