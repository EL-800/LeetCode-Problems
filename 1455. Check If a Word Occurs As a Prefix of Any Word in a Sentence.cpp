#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream sout(sentence);
        string word;
        int count = 1;
        while (sout >> word) {
            int i = 0;
            for (; i < searchWord.length() && i < word.length() && searchWord[i] == word[i]; i++);
            if (i == searchWord.length())
                return count;
            count++; 
        }
        return -1;
    }
};

int main() {
    return 0;
}