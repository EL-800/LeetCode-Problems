#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int indSpaces = 0;
        string ans;
        for (int i = 0; i < s.length(); i++) {
            if (indSpaces < spaces.size() && spaces[indSpaces] == i) {
                ans.push_back(' ');
                indSpaces++;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};

int main() {
    return 0;
}