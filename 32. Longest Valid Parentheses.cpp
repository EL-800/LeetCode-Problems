#include <bits/stdc++.h>

using namespace std;

class Solution {    
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> open;
        vector<int> wellFormed(n + 1);        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                open.push(i);
            else if (!open.empty()) {
                wellFormed[open.top()] += 1;
                wellFormed[i + 1] -= 1;
                open.pop();
            }
        }
        int ans = 0, curr = 0, flag = 0;        
        for (int i = 0; i < n; i++) {            
            flag += wellFormed[i];            
            if (flag)
                ans = max(ans, ++curr);
            else
                curr = 0;
        }
        return ans;
    }
};

int main() {
    return 0;
}