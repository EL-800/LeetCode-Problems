#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0, r = (int)tokens.size() - 1, ans = 0, currS = 0;
        while (l <= r && (power >= tokens[l] || currS)) {
            while (l <= r && power >= tokens[l]) {
                power -= tokens[l++];
                currS++;
            }
            ans = max(ans, currS);
            if (l <= r && currS) {
                power += tokens[r--];
                currS--;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}