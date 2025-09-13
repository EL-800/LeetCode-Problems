#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freqCount;
        for (char c : s) 
            freqCount[c]++;
        int maxCons = 0, maxVow = 0;
        for (auto [letter, count] : freqCount) {
            if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
                maxVow = max(maxVow, count);
            else
                maxCons = max(maxCons, count);
        }
        return maxCons + maxVow;        
    }
};

int main() {
    return 0;
}