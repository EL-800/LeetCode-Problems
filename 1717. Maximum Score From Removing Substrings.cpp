#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int CountSubstring(string &s, string sub) {        
        int count = 0, n = s.length();
        if (n < 2)
            return 0;
        stack<char> pile;        
        for (int i = 0; i < n; i++) {
            if (pile.empty()) {
                pile.push(s[i]);
                continue;
            }            
            string curr = string(1, pile.top()) + s[i];
            if (curr == sub) {
                count++;
                pile.pop();
            }
            else 
                pile.push(s[i]);                            
        }
        string modified = "";
        while (!pile.empty()) {
            modified += pile.top();
            pile.pop();
        }
        reverse(modified.begin(), modified.end());
        s = modified;
        return count;    
    }

public:
    int maximumGain(string s, int x, int y) {
        if (x > y) 
            return CountSubstring(s, "ab") * x + CountSubstring(s, "ba") * y;        
        return CountSubstring(s, "ba") * y + CountSubstring(s, "ab") * x;        
    }
};

int main() {
    Solution s;
    cout << s.maximumGain("cdbcbbaaabab", 4, 5);
    return 0;
}