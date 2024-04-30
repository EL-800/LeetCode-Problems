#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, long long> prefixesCount;
        prefixesCount[0] = 1;
        int currPrefix = 0;
        long long ans = 0;
        for (char letter : word){
            currPrefix ^= 1 << (letter - 'a');            
            ans += prefixesCount[currPrefix];
            for (int i = 1; i <= 512; i <<= 1)
                ans += prefixesCount[currPrefix ^ i];
            prefixesCount[currPrefix]++;
        }
        return ans;
    }
};

int main(){
    return 0;
}