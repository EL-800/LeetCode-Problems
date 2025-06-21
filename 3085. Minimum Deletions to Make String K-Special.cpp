#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26);
        for (char c : word)
            freq[c - 'a']++;
        sort(freq.begin(), freq.end());

        int n = freq.size(), prevDelCount = 0, ans = INT_MAX;
        for (int i = 0; i < n; i++) {            
            int delCount = 0;
            for (int j = i + 1; j < n; j++) 
                delCount += max(freq[j] - (freq[i] + k), 0);            
            ans = min(ans, delCount + prevDelCount);
            prevDelCount += freq[i];
        }
        return ans;
    }
};

int main() {
    return 0;
}