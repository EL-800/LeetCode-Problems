#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    char Shift(char l, int d) {
        l -= 'a';
        l = (l + d) % 26;
        return l >= 0 ? l + 'a' : l + 'z' + 1; 
    }

public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> sweepLine(n + 1);
        for (auto shift : shifts) {
            int start = shift[0], end = shift[1], add = shift[2] == 0 ? -1 : 1;
            sweepLine[start] += add;
            sweepLine[end + 1] -= add;
        }
        int move = 0;
        string ans;
        for (int i = 0; i < n; i++) {
            move += sweepLine[i];
            ans += Shift(s[i], move);
        }
        return ans;
    }
};

int main() {
    return 0;
}