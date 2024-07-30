#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {        
        int leftB = 0, rightA = 0;
        for (char c : s) 
            rightA += c == 'a';
        int ans = rightA;
        for (char c : s) {
            rightA -= c == 'a';
            leftB += c == 'b';
            ans = min(ans, rightA + leftB);
        }
        return ans;
    }
};

int main() {
    return 0;
}