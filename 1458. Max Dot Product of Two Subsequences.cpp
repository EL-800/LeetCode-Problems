#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    vector<int> nums1, nums2;
    
    int FindMax(vector<vector<vector<int>>> &dp, int i = 0, int j = 0, bool nonEmpty = false){
        if (i == n || j == m) 
            return nonEmpty ? 0 : INT_MIN;
        if (dp[i][j][nonEmpty] != INT_MIN)
            return dp[i][j][nonEmpty];
        return dp[i][j][nonEmpty] = max({FindMax(dp, i + 1, j, nonEmpty), FindMax(dp, i, j + 1, 
            nonEmpty), FindMax(dp, i + 1, j + 1, nonEmpty | true) + nums1[i] * nums2[j]});
    }

public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        this->nums1 = nums1;
        this->nums2 = nums2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, INT_MIN)));
        return FindMax(dp);
    }
};

int main(){
    return 0;
}