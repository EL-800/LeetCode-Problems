#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> memo;

    int dp(string& s, int k, int ind, int last){
        if (ind >= s.length())
            return 0;
        if (memo[ind][last] != -1)
            return memo[ind][last];
        int left = 0, right = 0, currLetter = (s[ind] - 'a');        
        if (abs(currLetter - last) <= k)
            left = dp(s, k, ind + 1, s[ind] - 'a') + 1;
        right = dp(s, k, ind + 1, last);       
        return memo[ind][last] = max(left, right);
    }

public:
    int longestIdealString(string& s, int k) {
        int n = s.length();
        memo.assign(n, vector<int>(25, -1)); 
        int best = 0;
        for (int i = 0; i < n; i++)
            best = max(dp(s, k, i, s[i] - 'a'), best); 
        return best;
    }
};

int main(){
    return 0;
}