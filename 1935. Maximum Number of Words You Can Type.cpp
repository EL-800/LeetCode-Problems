#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream sText(text);
        string curr;
        int ans = 0;
        while (sText >> curr) {
            bool flag = true;
            for (char c : curr) {
                if (count(brokenLetters.begin(), brokenLetters.end(), c)) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }
};

int main() {
    return 0;
}