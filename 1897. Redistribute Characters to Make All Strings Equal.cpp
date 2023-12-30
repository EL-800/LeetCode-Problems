#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26);
        for (string word : words){
            for (char c : word)
                freq[c - 'a']++;
        }
        int n = words.size();
        return find_if(freq.begin(), freq.end(), [&n](int fr){ return bool(fr % n); }) == freq.end();
    }
};

int main(){
    return 0;
}