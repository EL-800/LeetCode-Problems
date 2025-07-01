#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 0, curr = 0;
        for (int i = 1; i < word.length(); i++) {
            if (word[i] != word[i - 1]) {
                ans += curr;
                curr = 0;                
            }          
            else
                curr++;
        }
        return ans + curr + 1;
    }
};

int main() {
    return 0;
}