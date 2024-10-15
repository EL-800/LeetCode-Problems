#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0, curr = 0;
        for (char c : s) {
            if (c == '1')
                curr++;
            else 
                ans += curr;                            
        }
        return ans;
    }
};

int main() {
    return 0;
}