#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> letterCount;
        for (char c : s)
            letterCount[c]++;
        int odd = 0, lenght = 0;
        for (auto [letter, count] : letterCount){
            lenght += count / 2 * 2;
            odd |= count % 2;
        }
        return lenght + odd;
    }
};

int main(){
    return 0;
}