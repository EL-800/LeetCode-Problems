#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        string ans;
        vector<bool> have(26);
        vector<int> lastInd(26);
        for (int i = 0; i < s.length(); i++)
            lastInd[s[i] - 'a'] = i;
        for (int i = 0; i < s.length(); i++) {            
            if (have[s[i] - 'a'])
                continue;
            while (ans.length() > 0 && ans.back() > s[i] && i < lastInd[ans.back() - 'a']) {
                have[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            have[s[i] - 'a'] = true;
            ans.push_back(s[i]);
        }        
        return ans;
    }
};

int main() {
    return 0;
}