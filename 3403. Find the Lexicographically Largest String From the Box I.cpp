#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1)
            return word;
        int size = 0;
        string ans = "";        
        int n = word.size();        
        for (int i = 0; i < n; i++) {
            int ind = 0;
            for (int j = i; j < n; j++) {
                if (i + (n - j) < numFriends)
                    break;                                
                if (ind >= ans.length()) {
                    size++;
                    ans += word[j];       
                }                             
                else if (word[j] > ans[ind] || ind >= size) {
                    size = ind + 1;
                    ans[ind] = word[j];
                }
                else if (word[j] < ans[ind])
                    break; 
                ind++;               
            }
        }
        return ans.substr(0, size);
    }
};

int main() {
    string s = "dbca";
    Solution b;
    cout << b.answerString(s, 2);
    return 0;
}