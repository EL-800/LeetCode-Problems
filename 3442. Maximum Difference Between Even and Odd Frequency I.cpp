#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26);
        for (char c : s)
            freq[c - 'a']++;
        
        int maxOdd = 0, minEven = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2)
                maxOdd = max(maxOdd, freq[i]);
            else if (freq[i])
                minEven = min(minEven, freq[i]);
        }
        return maxOdd - minEven;
    }
};

int main() {
    return 0;
}