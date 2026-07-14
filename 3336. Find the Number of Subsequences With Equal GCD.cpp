#include <bits/stdc++.h>

using namespace std;

int memo[202][202][202];
int calculatedGCD[201][201];
int init = []() {
    for (int i = 0; i <= 200; i++)
        for (int j = 0; j <= 200; j++) 
            calculatedGCD[i][j] = __gcd(i,j);
    return 0;
}();

class Solution {
private:
    const int mod = 1e9 + 7;
    int n = 0;

    int dp(vector<int>& nums, int ind = 0, int gcd1 = 0, int gcd2 = 0) {
        if (ind == n)
            return (gcd1 == gcd2 && gcd1);
        if (memo[ind][gcd1][gcd2] != -1)
            return memo[ind][gcd1][gcd2];        
        
        return memo[ind][gcd1][gcd2] = ((dp(nums, ind + 1, gcd1 == 0 ? nums[ind] : calculatedGCD[gcd1][nums[ind]], gcd2) + 
                                        dp(nums, ind + 1, gcd1, gcd2 == 0 ? nums[ind] : calculatedGCD[gcd2][nums[ind]])) % mod + 
                                        dp(nums, ind + 1, gcd1, gcd2)) % mod;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(memo, -1, sizeof(memo));
        return dp(nums);
    }
};

int main() {
    return 0;
}