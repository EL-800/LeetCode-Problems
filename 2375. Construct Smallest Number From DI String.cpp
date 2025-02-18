#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        bool IsValid(string &pattern, string &curr) {
            int n = pattern.length();            
            for (int i = 0; i < n; i++) {
                if (pattern[i] == 'I' && curr[i] > curr[i + 1]) 
                    return false;
                if (pattern[i] == 'D' && curr[i] < curr[i + 1])
                    return false;                                                    
            }
            return true;
        }

    public:
        string smallestNumber(string pattern) {
            int n = pattern.length();
            string curr;
            for (char i = '1'; i <= n + '0' + 1; i++)
                curr.push_back(i);            
            do {
                if (IsValid(pattern, curr))
                    return curr;                     
            } while (next_permutation(curr.begin(), curr.end()));
            return "";              
        }
    };

int main() {
    return 0;
}