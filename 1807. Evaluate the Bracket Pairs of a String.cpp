#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dictionary;
        for (auto &pair : knowledge) 
            dictionary[pair[0]] = pair[1];        

        string ans;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                string curr;
                i++;
                while (s[i] != ')') 
                    curr += s[i++];
                if (dictionary.count(curr))
                    ans += dictionary[curr];
                else 
                    ans += '?';
            }
            else 
                ans += s[i];            
        }

        return ans;
    }
};

int main() {
    return 0;
}