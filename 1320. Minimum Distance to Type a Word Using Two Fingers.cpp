#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<vector<int>>> memo;
    vector<pair<int, int>> letterPos;

    int GetDis(char let1, char let2) {
        if (let1 == 'Z' + 1)
            return 0;
        auto pos1 = letterPos[let1 - 'A'], pos2 = letterPos[let2 - 'A'];
        return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
    }

    int dp(string &word, char finger1 = 'Z' + 1, char finger2 = 'Z' + 1, int ind = 0) {
        if (ind == word.length())
            return 0;
        if (memo[finger1 - 'A'][finger2 - 'A'][ind] != -1)
            return memo[finger1 - 'A'][finger2 - 'A'][ind];
        
        int useFinger1 = dp(word, word[ind], finger2, ind + 1) + GetDis(finger1, word[ind]);
        int useFinger2 = dp(word, finger1, word[ind], ind + 1) + GetDis(finger2, word[ind]);

        return memo[finger1 - 'A'][finger2 - 'A'][ind] = min(useFinger1, useFinger2);
    }

public:
    int minimumDistance(string word) {        
        memo.assign(27, vector<vector<int>>(27, vector<int>(word.length(), -1)));
        letterPos.resize(26);

        int currLetter = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6 && currLetter < 26; j++, currLetter++)
                letterPos[currLetter] = {i, j};
        }

        return dp(word);
    }
};

int main() {
    return 0;
}