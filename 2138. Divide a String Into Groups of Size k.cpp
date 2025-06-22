#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string curr;
        for (int i = 0; i < s.length(); i++) {
            curr += s[i];
            if ((i + 1) % k == 0) { 
                ans.push_back(curr);
                curr.clear();                
            }       
        }
        if (curr.size())
            ans.push_back(curr + string(k - curr.size(), fill));
        return ans;
    }
};

int main() {
    return 0;
}