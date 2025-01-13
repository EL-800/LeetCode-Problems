#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> freqCount;
        for (char l : s)
            freqCount[l]++;
        int ans = 0;
        for (auto [letter, freq] : freqCount)
            ans += freq % 2 ? 1 : 2;
        return ans;
    }
};

int main() {
    return 0;
}