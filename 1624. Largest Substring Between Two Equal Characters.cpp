#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> leftChar(26, INT_MAX), rightChar(26, INT_MAX);
        for (int i = 0; i < s.length(); i++){
            leftChar[s[i] - 'a'] = min(leftChar[s[i] - 'a'], i);
            rightChar[s[i] - 'a'] = i;
        }   
        int maxDiff = -1;     
        for (int i = 0; i < 26; i++){
            if (leftChar[i] == rightChar[i])
                continue;
            maxDiff = max(maxDiff, rightChar[i] - leftChar[i] - 1);
        }
        return maxDiff;
    }
};

int main(){
    return 0;
}