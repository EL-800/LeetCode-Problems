#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i += 2) 
            ans += s[i] != s[i + 1];        
        return ans;
    }
};

int main() {
    return 0;
}