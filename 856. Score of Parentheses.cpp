#include <bits/stdc++.h>

using namespace std;

class Solution {
public:    
    int scoreOfParentheses(string s) {
        int ans = 0, val = 1;        
         for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') 
                val *= 2;    
            else {
                val /= 2;
                if (s[i - 1] == '(')
                    ans += val;
            }                    
         }
         return ans;
    }
};

int main() {
    return 0;
}