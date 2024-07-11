#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    string Recursion(string& s, vector<int>& brackets, int i, int d) {
        string t = "";
        while (1) {
            if (s[i] == '(' && d == -1)
                return t;
            else if (s[i] == ')' && d == -1) {
                t += Recursion(s, brackets, brackets[i] + 1, 1);
                i = brackets[i] - 1;
            }
            else if (s[i] == '(' && d == 1) {
                t += Recursion(s, brackets, brackets[i] - 1, -1);
                i = brackets[i] + 1;
            }
            else if (s[i] == ')' && d == 1)
                return t;
            else { 
                t += s[i];
                i += d;
            }
        }        
        return t;            
    }

public:
    string reverseParentheses(string s) {
        vector<int> brackets (s.length());
        stack<int> bracketsP;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                bracketsP.push(i);
            else if (s[i] == ')') {
                int begin = bracketsP.top();
                bracketsP.pop();
                brackets[i] = begin;
                brackets[begin] = i;
            }                
        }
        string ans = "";
        int i = 0;
        while (i < s.length()) {
            if (s[i] == '(') {
                ans += Recursion(s, brackets, brackets[i] -1, -1);
                i = brackets[i] + 1;
            }
            else {
                ans += s[i];
                i++;
            }                
        }        
        return ans;
    }
};

int main() {
    Solution s;
    s.reverseParentheses("(ed(et(oc))el)");
    return 0;
}