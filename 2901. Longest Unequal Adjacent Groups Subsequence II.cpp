#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<int> memo, path; 

    int HammingPath(string a, string b) {
        if (a.length() != b.length())
            return 0;
        int count = 0;
        for (int i = 0; i < a.length(); i++) 
            count += a[i] != b[i];        
        return count;
    }
    
    int dp(vector<string>& words, vector<int>& groups, int ind) {
        if (memo[ind] != -1)
            return memo[ind];
        memo[ind] = 1;
        for (int i = ind + 1; i < n; i++) {
            if (HammingPath(words[ind], words[i]) != 1)
                continue;
            if (groups[ind] == groups[i])
                continue;            
            int validNext = dp(words, groups, i) + 1;
            if (memo[ind] < validNext) {
                memo[ind] = validNext;
                path[ind] = i;
            }                
        }
        return memo[ind];
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        n = words.size();
        memo.assign(n, -1);
        path.assign(n, -1);
        for (int i = 0; i < n; i++)
            dp(words, groups, i);
        int ansInd = max_element(memo.begin(), memo.end()) - memo.begin();
        vector<string> ans;
        while (ansInd != -1) {
            ans.push_back(words[ansInd]);
            ansInd = path[ansInd];
        }
        return ans;
    }
};

int main() {
    return 0;
}