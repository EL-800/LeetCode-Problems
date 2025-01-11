#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k)
            return false;
        unordered_map<char, int> characterFreq;
        for (char let : s)
            characterFreq[let]++;
        int odds = 0;
        for (auto freq : characterFreq)
            odds += freq.second % 2;   
        return k >= odds;     
    }
};

int main() {
    return 0;
}