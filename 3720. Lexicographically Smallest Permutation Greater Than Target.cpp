#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();

        unordered_map<char, int> count;
        for (char c : s) 
            count[c]++;        
        
        string prefix;
        for (int i = 0; i < n; i++) {
            char c = target[i];            
            if (!count[c]) 
                break;            
            count[c]--;
            prefix.push_back(c);
        }
        
        if (prefix.size() < n) {                        
            for (char c = target[prefix.size()] + 1; c <= 'z'; c++) {
                if (!count[c])
                    continue;

                string ans = prefix;
                ans.push_back(c);
                count[c]--;
                for (char ch = 'a'; ch <= 'z'; ch++) 
                    ans.append(count[ch], ch);

                return ans;
            }
        }

        for (int i = prefix.size() - 1; i >= 0; i--) {            
            count[prefix[i]]++;
            prefix.pop_back();                        
            for (char c = target[i] + 1; c <= 'z'; c++) {
                if (!count[c])
                    continue;

                string ans = prefix;
                ans.push_back(c);
                count[c]--;                
                for (char ch = 'a'; ch <= 'z'; ch++) 
                    ans.append(count[ch], ch);                

                return ans;
            }
        }

        return "";
    }
};

int main() {
    return 0;
}