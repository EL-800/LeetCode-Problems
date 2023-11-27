#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool IsVowel(char c){
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    string sortVowels(string s) {
        string vowels;
        for (char c : s){
            if (IsVowel(c))
                vowels.push_back(c);
        }
        sort(vowels.begin(), vowels.end());
        int vowInd = 0;
        for (int i = 0; i < s.length(); i++){
            if (IsVowel(s[i]))
                s[i] = vowels[vowInd++];            
        }
        return s;
    }
};

int main(){
    return 0;
}