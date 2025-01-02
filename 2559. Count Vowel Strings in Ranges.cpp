#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int IsVowel(char l) {
        return l == 'a'|| l == 'e' || l == 'i' || l == 'o' || l == 'u';
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> calculed(n + 1);
        for (int i = 1; i <= n; i++) {
            int isValid = IsVowel(*words[i - 1].begin()) && IsVowel(*words[i - 1].rbegin());
            calculed[i] = isValid + calculed[i - 1];
        }
        vector<int> ans;
        for (auto query : queries) {
            int left = query[0], right = query[1];
            ans.push_back(calculed[right + 1] - calculed[left]);
        }
        return ans;
    }
};

int main() {
    return 0;
}