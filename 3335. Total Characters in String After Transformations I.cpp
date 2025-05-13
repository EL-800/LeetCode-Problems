#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int mod = 1e9 + 7;
        vector<int> characterCount(26);
        for (auto c : s)
            characterCount[c - 'a']++;
        while (t--) {
            vector<int> auxiliarCount(26);
            for (char i = 0; i < 25; i++) 
                auxiliarCount[i + 1] = characterCount[i];            
            auxiliarCount[0] = characterCount[25];
            auxiliarCount[1] = (auxiliarCount[1] + characterCount[25]) % mod;
            characterCount = auxiliarCount;
        }
        int ans = 0;
        for (int val : characterCount)
            ans = (ans + val) % mod;
        return ans % mod;
    }
};

int main() {
    return 0;
}