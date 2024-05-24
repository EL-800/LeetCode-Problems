#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int CalculateScore(string& word, vector<int> lettersCnt, vector<int>& score){
        int currScore = 0;
        for (char let : word){
            if (!lettersCnt[let - 'a'])
                return -1;
            lettersCnt[let - 'a']--;
            currScore += score[let - 'a'];
        }
        return currScore;
    }

    void AddLettersCnt(string& word, vector<int>& lettersCnt, int add = 1){
        for (char let : word)
            lettersCnt[let - 'a'] += add;                
    }

    int SearchBest(vector<string>& words, vector<int>& lettersCnt, vector<int>& score, int ind = 0){
        if (ind == words.size())
            return 0;
        int left = 0, right = 0, aux = 0;
        if ((aux = CalculateScore(words[ind], lettersCnt, score)) != -1) {
            AddLettersCnt(words[ind], lettersCnt, -1);
            left = aux + SearchBest(words, lettersCnt, score, ind + 1);
            AddLettersCnt(words[ind], lettersCnt);        
        }
        right = SearchBest(words, lettersCnt, score, ind + 1);
        return max(left, right);
    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> lettersCnt(26);
        for (char let : letters)
            lettersCnt[let - 'a']++;
        return SearchBest(words, lettersCnt, score);
    }
};

int main(){
    vector<string> words = {"dog","cat","dad","good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
    vector<int> score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    Solution s;
    cout << s.maxScoreWords(words, letters, score);
    return 0;
}