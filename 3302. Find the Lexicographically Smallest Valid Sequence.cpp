#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> suffixInd(m, -1);
        
        int i = n - 1, j = m - 1;        
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j])
                suffixInd[j--] = i;
            i--;
        }

        vector<int> ans;        
        bool flag = false;        
        for (i = 0, j = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } 
            else if (!flag && (j == m - 1 || i < suffixInd[j + 1])) {                
                ans.push_back(i);
                j++;
                flag = true;
            }
        }

        return j == m ? ans : vector<int>();
    }
};

int main() {
    return 0;
}