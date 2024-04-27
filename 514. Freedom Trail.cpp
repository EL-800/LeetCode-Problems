#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> memo;

    int dp(string& ring, string& key, int ringInd = 0, int keyIndex = 0){
        if (keyIndex >= key.length())
            return 0;        
        if (memo[ringInd][keyIndex] != INT_MAX)
            return memo[ringInd][keyIndex];        
        for (int i = 0; i < ring.length(); i++){
            if (ring[i] == key[keyIndex]){                
                int diff = min(abs(ringInd - i), (int)ring.length() - abs(ringInd - i));
                memo[ringInd][keyIndex] = min(memo[ringInd][keyIndex], dp(ring, key, i, keyIndex + 1) + diff + 1);
            }
        }
        return memo[ringInd][keyIndex];
    }

public:
    int findRotateSteps(string ring, string key) {
        memo.assign(ring.length(), vector<int>(key.length(), INT_MAX));
        return dp(ring, key);
    }
};

int main(){
    Solution s;
    cout << s.findRotateSteps("godding", "gd");
    return 0;    
}