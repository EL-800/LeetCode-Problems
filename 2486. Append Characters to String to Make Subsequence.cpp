#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int indS = 0, indT = 0;
        while (indS < s.length() && indT < t.length()){            
            if (s[indS] == t[indT])
                indT++;
            indS++;
        }
        return t.length() - indT - 1;
    }
};

int main(){
    return 0;
}