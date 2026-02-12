#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length(), lettersSize = 26, ans = 0;        

        for (int i = 0; i < n; i++) {
            vector<int> characterCount(lettersSize);
            for (int j = i; j < n; j++) {
                int codifiedChar = s[j] - 'a';
                characterCount[codifiedChar]++;
                int pivot = characterCount[codifiedChar]; 
                bool isBalanced = all_of(characterCount.begin(), characterCount.end(), [&pivot](const int curr) {
                    if (!curr)
                        return true;
                    return pivot == curr;
                });
                if (isBalanced)
                    ans = max(ans, j - i + 1);
            }            
        }

        return ans;
    }
};

int main() {
    return 0;
}