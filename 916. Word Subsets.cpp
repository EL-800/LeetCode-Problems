#include <bits/stdc++.h>

using namespace std;

class Solution {
private:    
    inline void GetFreq(int (*freq)[26], vector<string>& words) {
        int n = words.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++)
                freq[i][j] = 0;
        }

        for (int i = 0; i < n; i++) {
            string &word = words[i];
            for (char let : word) {
                freq[i][let - 'a']++;
            } 
        }
    }

    inline bool IsSubset(int (*freq1), int (*freq2)) {
        for (int i = 0; i < 26; i++) {
            if (freq2[i] && freq2[i] > freq1[i])
                return false;
        }
        return true;
    }

public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(), m = words2.size();  
        int freq1[n][26], freq2[m][26];              
        GetFreq(freq1, words1);
        GetFreq(freq2, words2);

        vector<string> ans;

        for (int i = 0; i < n; i++) {
            bool aux = true;
            for (int j = 0; j < m; j++) {
                if (!IsSubset(freq1[i], freq2[j])) {
                    aux = false;
                    break;                   
                }
            }
            if (aux)
                ans.push_back(words1[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> a = {"amazon","apple","facebook","google","leetcode"};
    vector<string> b = {"e", "o"};
    s.wordSubsets(a, b);

    return 0;
}