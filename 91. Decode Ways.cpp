#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<int> dp;
    string s;

    bool IsValid(int i, int m) {                
        if (!m && s[i] == '0')
            return false;
        else if (m) {
            if (s[i - 1] == '0')
                return false;
            if (s[i - 1] == '2' && s[i] > '6')
                return false;
            if (s[i - 1] > '2')
                return false;
        }
        return true;
    }

    int FindWays(int i = -1, int m = 0) {
        if (i >= n)
            return 0;
        if (i != -1 && !IsValid(i, m))
            return 0;
        if (i == n - 1)
            return 1;
        if (dp[i + 1] != -1)
            return dp[i + 1];
        return dp[i + 1] = FindWays(i + 1, 0) + FindWays(i + 2, 1);
    }

public:
    int numDecodings(string s) {
        n = s.size();
        dp.assign(n, -1);
        this->s = s;
        return FindWays();
    }
};

int main(){
    return 0;
}