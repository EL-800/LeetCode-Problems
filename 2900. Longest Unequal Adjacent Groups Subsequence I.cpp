#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> ans;
        ans.push_back(words[0]);
        for (int i = 1; i < n; i++) {
            if (groups[i] != groups[i - 1])
                ans.push_back(words[i]);
        }
        return ans;
    }
};

int main() {
    return 0;
}