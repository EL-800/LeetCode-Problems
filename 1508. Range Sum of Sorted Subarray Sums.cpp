#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int mod = 1e9 + 7;
        vector<int> sums;                
        for (int i = 0; i < n; i++) {
            int currSum = 0;
            for (int j = i; j < n; j++) {
                currSum += nums[j];
                sums.push_back(currSum);
            }
        }
        sort(sums.begin(), sums.end());
        int ans = 0;
        for (int i = left - 1; i < right; i++) {
            ans = (ans + sums[i]) % mod;
        }
        return ans;        
    }
};

int main() {
    return 0;
}