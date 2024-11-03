#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        for (int i = 0; i < s.length(); i++) {
            int j = i, gInd = 0;
            for (; gInd < goal.length(); gInd++) {
                if (s[j] != goal[gInd])
                    break;
                j = (j + 1) % s.length();                                    
            }
            if (gInd == goal.length())
                return true;
        }
        return false;
    }
};

int main() {
    return 0;
}