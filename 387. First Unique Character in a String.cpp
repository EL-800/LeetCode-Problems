#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {        
        vector<int> ocurrences(26, 0);
        vector<int> fAppears(26, INT_MAX);
        int n = s.length();
        for (int i = 0; i < s.length(); i++){
            ocurrences[s[i] - 'a']++;
            fAppears[s[i] - 'a'] = min( fAppears[s[i] - 'a'], i);
        }
        int ans = INT_MAX;
        for (int i = 0; i< 26; i++){
            if (ocurrences[i] == 1)
                ans = min(ans, fAppears[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(){
    return 0;
}