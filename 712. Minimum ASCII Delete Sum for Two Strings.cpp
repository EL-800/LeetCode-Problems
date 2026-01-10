#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<int>> dp;    
    string s1, s2;

    int FindMin(int left = 0, int right = 0) {
        if (left == n && right == m)
            return 0;
        if (dp[left][right] != -1)
            return dp[left][right];
        if (left == n)
            return dp[left][right] = FindMin(left, right + 1) + s2[right];
        if (right == m)
            return dp[left][right] = FindMin(left + 1, right) + s1[left];
        if (s1[left] == s2[right])
            return dp[left][right] = FindMin(left + 1, right + 1);
        return dp[left][right] = min(FindMin(left + 1, right) + s1[left], FindMin(left, right + 1) + s2[right]);
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        n = s1.length(), m = s2.length();
        this->s1 = s1, this->s2 = s2;
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return FindMin();
    }
};

int main() {
    return 0;
}