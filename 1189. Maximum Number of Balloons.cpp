#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {        
        unordered_map<char, int> charCount;
        for (char c : text) 
            charCount[c]++;        

        int ans = INT_MAX;
        vector<pair<char, int>> searchedWord = {{'b', 1}, {'a', 1}, {'l', 2}, {'o', 2}, {'n', 1}};
        for (auto &[c, ocurr] : searchedWord) 
            ans = min(ans, charCount[c] / ocurr);        
        
        return ans;
    }
};

int main() {
    return 0;
}