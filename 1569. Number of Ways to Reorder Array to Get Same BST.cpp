#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int mod = 1e9 + 7;

    int computeComb(int n, int k){
        if (k > n / 2) 
            k = n - k;
            
        vector<int> comb(k + 1, 0), prevC(k + 1, 0);
        for(int i = 0; i <= n; i++){
            comb[0] = 1;
            for(int j = 1; j <= min(i, k); j++){
                comb[j] = ((long)prevC[j-1] + prevC[j]) % mod;  
            }
            prevC = comb;  
        }

        return comb[k];
    }

    long long function(vector<int> &nums) {
        if (nums.size() <= 2)
            return 1;
        
        vector<int> left, right;        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);            
        }            

        long long solveLeft = function(left), solveRight = function(right);        
        return computeComb(nums.size() - 1, left.size()) * solveLeft % mod * solveRight % mod;
    }

public:
    int numOfWays(vector<int>& nums) {
        return (function(nums) - 1) % mod;
    }
};

int main() {
    return 0;
}