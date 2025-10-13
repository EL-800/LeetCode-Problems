#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool CheckAnagram(string a, string b) {
        vector<int> countA(26), countB(26);

        for (char c : a)
            countA[c - 'a']++;
        for (char c : b)
            countB[c - 'a']++;

        return countA == countB;
    }

public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;

        for (auto word : words) {
            if (ans.empty())
                ans.push_back(word);  
            else if (!CheckAnagram(ans.back(), word))
                ans.push_back(word);  
        }  
        
        return ans;
    }
};

int main() {
    return 0;
}