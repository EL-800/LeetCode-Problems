#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string word) {
        return regex_match(word, regex("(?=.*[b-df-hj-np-tv-z])(?=.*[aeiou])[a-zA-Z0-9]{3,}", regex_constants::icase));
    }
};

int main() {
    return 0;
}