#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string &word) {        
        unordered_map<char, int> firstUpper, lastLower;

        for (int i = 0; i < word.length(); i++) {
            if (islower(word[i]))
                lastLower[word[i]] = i;
            else if (!firstUpper.count(word[i]))
                firstUpper[word[i]] = i;
        }

        const int diff = 'a' - 'A';
        int ans = 0;
        for (auto [c, ind] : firstUpper) {
            if (lastLower.count(c + diff) && ind > lastLower[c + diff])
                ans++;
        }

        return ans;
    }
};

int main() {        
    return 0;
}