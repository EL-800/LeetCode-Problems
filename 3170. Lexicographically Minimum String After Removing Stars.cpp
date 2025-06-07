#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string clearStars(string s) {
        int n = s.length();
        vector<stack<int>> letters(26);
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                int letInd = 0;
                while (letters[letInd].empty())
                    letInd++;
                letters[letInd].pop();
            }
            else
                letters[s[i] - 'a'].push(i);
        }

        vector<pair<int, char>> indLett;
        for (int i = 0; i < 26; i++) {
            while (!letters[i].empty()) {
                indLett.push_back({letters[i].top(), i + 'a'});
                letters[i].pop();
            }
        }
        sort(indLett.begin(), indLett.end());

        string ans;
        for (auto [ind, lett] : indLett)
            ans += lett;
        return ans;
    }
};

int main() {
    return 0;
}