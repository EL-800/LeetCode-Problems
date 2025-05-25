#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {        
        map<string, int> strings;
        int ans = 0, f = false;
        for (string i : words)
            strings[i]++;
        for (string i : words) {
            string r = i;
            reverse(r.begin(), r.end());            
            if (i[0] == i[1] && strings[i] == 1) {
                if (f)
                    continue;
                f = true;
                ans += 2;
                strings[i]--;
            }
            else if (strings[i] && strings.find(r) != strings.end() && strings[r]) {
                strings[i]--;
                strings[r]--;
                ans += 4;
            }            
        }
        return ans;
    }
};

int main() {
    return 0;
}