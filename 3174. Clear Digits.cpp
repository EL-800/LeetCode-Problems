#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string clearDigits(string s) {
            string ans;
            for (char l : s) {
                if (l >= '0' && l <= '9' && ans.empty())
                    continue;
                else if (l >= '0' && l <= '9')
                    ans.pop_back();
                else
                    ans.push_back(l);                     
            }
            return ans;
        }
    };

int main() {
    return 0;
}