#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool CanBeFormed(vector<int> bucketChar, string word){
        for (char l : word){
            if (!bucketChar[l - 'a'])
                return false;
            bucketChar[l - 'a']--;
        }
        return true;
    }

public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> bucketChar(26);
        for (char l : chars)
            bucketChar[l - 'a']++;
        int ans = 0;
        for (string word : words){
            if (CanBeFormed(bucketChar, word))
                ans += word.length();
        }
        return ans;
    }
};

int main(){
    return 0;
}