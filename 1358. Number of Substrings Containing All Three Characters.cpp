#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n = s.length(), left = 0, ans = 0;
            unordered_map<char, int> charCount;
            for (int right = 0; right < n; right++) {
                charCount[s[right]]++;
                while (left < right && charCount.size() == 3) {
                    ans += n - right;
                    charCount[s[left]]--;                    
                    if (!charCount[s[left]]) {                        
                        charCount.erase(s[left]);
                    }                    
                    left++;
                }                                
            }
            return ans;
        }
    };

int main() {
    return 0;
}