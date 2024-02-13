#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string word : words){
            int left = 0, right = word.length() - 1;
            while (left < right && word[left] == word[right]){                                
                left++;
                right--;
            }
            if (left >= right)
                return word;
        }
        return "";
    }
};

int main(){
    return 0;
}