#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int mod = (int)1e9 + 7;
    unordered_map<char, vector<char>> moves = {{'a', {'e'}}, {'e', {'a', 'i'}}, {'i', {'a', 'e', 'o', 'u'}}, 
                                                {'o', {'i', 'u'}}, {'u', {'a'}}, {'z', {'a', 'e', 'i', 'o', 'u'}}};

    int CountPer(vector<unordered_map<char, int>>& dp, int ind = 0, char lastVow = 'z'){
        if (ind == dp.size())
            return 1;
        if (dp[ind].count(lastVow))
            return dp[ind][lastVow];
        auto nexts = moves[lastVow];
        for (char next : nexts)
            dp[ind][lastVow] = (dp[ind][lastVow] + CountPer(dp, ind + 1, next)) % mod;        
        return dp[ind][lastVow] % mod;
    }

public:
    int countVowelPermutation(int n) {
        vector<unordered_map<char, int>> dp(n);
        return CountPer(dp);
    }
};

int main(){
    return 0;
}