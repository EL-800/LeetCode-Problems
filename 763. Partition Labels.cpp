#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int n = s.length();
            unordered_map<char, int> lastCharIndexes;
            for (int i = 0; i < n; i++) 
                lastCharIndexes[s[i]] = i;
            int lastChar = 0, currSize = 0;            
            vector<int> ans; 
            for (int i = 0; i < n; i++) {
                lastChar = max(lastChar, lastCharIndexes[s[i]]);
                currSize++;
                if (i == lastChar) {
                    ans.push_back(currSize);
                    currSize = 0;
                }
            }
            return ans;                       
        }
    };

int main() {
    return 0;
}