#include <bits/stdc++.h>

using namespace std;

int dp[101][27][101][101];
class Solution {
private:
    string s;
    int n, k;    

    int SearchMin(int i = 0, int last = 26, int countLast = 0, int used = 0) {
        if (used > k)
            return INT_MAX;
        if (i == n)
            return 0;
        if (dp[i][last][countLast][used] != -1)
            return dp[i][last][countLast][used];
        int del = SearchMin(i + 1, last, countLast, used + 1);
        int keep = 0;
        if (s[i] - 'a' == last) {
            keep = SearchMin(i + 1, last, countLast + 1, used);
            if (countLast == 1 || countLast == 9 || countLast == 99)
                keep += 1;
        }
        else
            keep = SearchMin(i + 1, s[i] - 'a', 1, used) + 1;
        return dp[i][last][countLast][used] = min(del, keep);
    }

public:
    int getLengthOfOptimalCompression(string s, int k) {
        this->s = s;
        this->k = k;
        n = s.size();        
        memset(dp,-1,sizeof(dp));        
        return SearchMin();
    }
};

int main(){
    return 0;
}