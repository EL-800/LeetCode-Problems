#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<string> VectorizeString(string sentence) {
        vector<string> words;
        stringstream s(sentence);
        string word;
        while (s >> word)
            words.push_back(word);
        return words;
    }

public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.size() > sentence2.size())
            swap(sentence1, sentence2);
        vector<string> words1 = VectorizeString(sentence1), words2 = VectorizeString(sentence2);        
        int left = 0;
        while (left < words1.size() && words1[left] == words2[left])
            left++;
        int right1 = words1.size() - 1, right2 = words2.size() - 1;
        while (right1 >= 0 && words1[right1] == words2[right2]) {
            right1--;
            right2--;
        }
        return left > right1;
    }
};

int main() {
    return 0;
}