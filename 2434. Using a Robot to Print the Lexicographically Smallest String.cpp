#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool BestNext(unordered_map<char, int> &freq, char c) {
        for (auto [key, val] : freq) {
            if (key < c)
                return true;                            
        }
        return false;             
    }

public:
    string robotWithString(string s) {
        int left = 0;
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        stack<char> t;
        string ans;   
        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]--;
            if (!freq[s[i]])
                freq.erase(s[i]);
            t.push(s[i]);
            while (!t.empty() && !BestNext(freq, t.top())) {
                ans += t.top();
                t.pop();
            }
        }        
        return ans;
    }
};

int main() {
    return 0;
}