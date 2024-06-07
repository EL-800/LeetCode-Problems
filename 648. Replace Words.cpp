#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> words(dictionary.begin(), dictionary.end());
        int ind = 0;
        string ans, currWord;
        while (ind < sentence.length()){
            if (words.count(currWord)){                
                while (ind < sentence.length() && sentence[ind] != ' ') ind++;                
            }
            if (ind == sentence.length())
                break;
            if (sentence[ind] == ' '){
                ans += currWord + " ";
                currWord = "";
            }
            else
                currWord += sentence[ind];            
            ind++;
        }
        ans += currWord;
        return ans;
    }
};

int main(){
    return 0;
}