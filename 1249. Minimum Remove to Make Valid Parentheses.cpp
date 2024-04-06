#include <bits/stdc++.h>

using namespace std;

class Solution {
private: 
    string RemoveInvalids(string s, char open, char closed){
        int openParentheses = 0;
        string validS;
        for (char c : s){
            if (c == open) {
                openParentheses++;
                validS += c;
            }
            else if (c == closed){
                if (openParentheses){
                    openParentheses--;
                    validS += c;                                                
                }                                
            }
            else
                validS += c;            
        }
        return validS;  
    }

public:
    string minRemoveToMakeValid(string s) {
        string firstCheck = RemoveInvalids(s, '(', ')');
        reverse(firstCheck.begin(), firstCheck.end());
        string secondCheck = RemoveInvalids(firstCheck, ')', '(');
        reverse(secondCheck.begin(), secondCheck.end());
        return secondCheck;
    }
};

int main(){
    Solution s;
    cout << s.minRemoveToMakeValid("lee(t(c)o)de)");
}