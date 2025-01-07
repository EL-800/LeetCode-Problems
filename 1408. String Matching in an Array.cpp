#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        ans.reserve(n);
        for (int i = 0; i < n; i++) {
            string word = words[i];
            for (int j = 0; j < n; j++) {
                if (i != j && words[j].find(word) != -1) {
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}