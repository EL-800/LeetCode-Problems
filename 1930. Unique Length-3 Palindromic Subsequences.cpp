#include <bits/stdc++.h>

using namespace std;

class Solution {
private: 
    unordered_map<char, vector<int>> letterInd;        

    bool FindSubsequence(string curr){
        int currInd = -1;      
        for (char i : curr){
            auto it = lower_bound(letterInd[i].begin(), letterInd[i].end(), currInd + 1);
            if (it == letterInd[i].end())
                return false;
            currInd = *it;
        }
        return true;
    }

    int FindPalindromes(string curr = ""){
        if (curr.length() == 3) {
            return curr[0] == curr[2] && FindSubsequence(curr) ? 1 : 0;
        }
        int count = 0;
        for (char i = 'a'; i <= 'z'; i++)
            count += FindPalindromes(curr + i);
        return count;
    }

public:
    int countPalindromicSubsequence(string s) {
        letterInd.clear();
        for (int i = 0; i < s.length(); i++)
            letterInd[s[i]].push_back(i);   
        return FindPalindromes();            
    }
};

int main(){
    Solution s;
    cout << s.countPalindromicSubsequence("adc");
    return 0;
}