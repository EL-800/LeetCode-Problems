#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int> > dp;

    int FindMin(const vector<vector<int>>& t, int r = 0, int c = 0) {
        if (r == t.size())
            return 0;
        if (c >= t[r].size())
            return 10000000;
        if (dp[r][c] != INT_MIN)
            return dp[r][c];        
        return dp[r][c] = min(FindMin(t, r + 1, c) + t[r][c], FindMin(t, r + 1, c + 1) + t[r][c]);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.assign(triangle.size(), vector<int>());
        for (int i = 0; i < triangle.size(); i++)
            dp[i].assign(triangle[i].size(), INT_MIN);
        return FindMin(triangle);
    }
};

int main() {
    return 0;
}