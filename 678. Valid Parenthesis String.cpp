#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool ValidString(string s, char open, char closed){
        int openParentheses = 0, countAstherics = 0;
        for (char c : s){
            if (c == open)
                openParentheses++;
            else if (c == '*')
                countAstherics++;
            else{
                if (openParentheses)
                    openParentheses--;
                else if (countAstherics)
                    countAstherics--;
                else
                    return false;
            }
        }
        return true;
    }

public:
    bool checkValidString(string s) {
        string rS = s;
        reverse(rS.begin(), rS.end());
        return ValidString(s, '(', ')') && ValidString(rS, ')', '(');
    }
};

int main(){
    return 0;
}