#include <bits/stdc++.h>

using namespace std;

class Solution {
private:    
    int Check(string &s, int start = 0, int move = 1, char open = '(') {
        int openCount = 0, ans = 0;
        for (int i = start; i >= 0 && i < s.length(); i += move) {
            if (s[i] == open) 
                openCount++;
            else
                openCount--;
            if (openCount < 0) {
                ans++;
                openCount++;
            }
        }
        return ans;
    }

public:
    int minAddToMakeValid(string s) {        
        return Check(s) + Check(s, s.length() - 1, -1, ')');
    }
};

int main() {
    return 0;
}