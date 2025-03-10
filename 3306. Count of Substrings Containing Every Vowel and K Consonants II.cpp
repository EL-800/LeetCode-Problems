#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long atLeastK(string& word, int k) {            
            long long ans = 0;            
            unordered_map<char, int> vowelsCount;
            string vowels = "aeiou";
            int n = word.length(), consonantCount = 0, left = 0;            
            for (int right = 0; right < n; right++) {
                if (count(vowels.begin(), vowels.end(), word[right])) 
                    vowelsCount[word[right]]++;                 
                else 
                    consonantCount++;                
                while (vowelsCount.size() == 5 && consonantCount >= k) {
                    ans += n - right;
                    if (count(vowels.begin(), vowels.end(), word[left])) {
                        vowelsCount[word[left]]--; 
                        if (!vowelsCount[word[left]]) 
                            vowelsCount.erase(word[left]);                                                                 
                    }
                    else 
                        consonantCount--;   
                    left++;
                }                
            }
            return ans;
        }
    
        long long countOfSubstrings(string word, int k) {
            return atLeastK(word, k) - atLeastK(word, k + 1);
        }
    };

int main() {
    return 0;
}