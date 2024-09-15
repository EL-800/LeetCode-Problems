#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isvowel(char v) {
        return (0x208222>>(v&0x1f))&1;
    }

public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> prefixes;
        int currPrefix = 0, ans = 0;    
        prefixes[0] = -1;    
        for (int i = 0; i < s.length(); i++) {
            if (isvowel(s[i]))
                currPrefix ^= 1 << (s[i] - 'a');
            if (prefixes.count(currPrefix)) {                            
                ans = max(ans, i - prefixes[currPrefix]);
            }
            else
                prefixes[currPrefix] = i;
        }
        return ans;
    }
};

int main() {
    return 0;
}