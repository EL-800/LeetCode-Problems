#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    string text1, text2;
    vector<vector<int>> dp;
    int n, m;

    int FindMax(int firstInd = 0, int secondInd = 0) {
        if (firstInd == n || secondInd == m)
            return 0;
        if (dp[firstInd][secondInd] != -1)
            return dp[firstInd][secondInd];
        if (text1[firstInd] == text2[secondInd])
            return dp[firstInd][secondInd] = FindMax(firstInd + 1, secondInd + 1) + 1;
        return dp[firstInd][secondInd] = max(FindMax(firstInd + 1, secondInd), FindMax(firstInd, secondInd + 1));
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        this->text1 = text1;
        this->text2 = text2;
        dp.assign(n, vector<int>(m, -1));
        return FindMax();
    }
};

int main(){
    return 0;
}