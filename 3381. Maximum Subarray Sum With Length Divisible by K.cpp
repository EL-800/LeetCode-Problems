#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size(), currSum = 0ll, ans = LLONG_MIN;
        vector<long long> minPrefix(k, LLONG_MAX);                  

        minPrefix[0] = 0;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];
            int mod = ((i + 1) % k);
            if (minPrefix[mod] != LLONG_MAX) 
                ans = max(ans, currSum - minPrefix[mod]);        
            minPrefix[mod] = min(minPrefix[mod], currSum);
        }
        return ans;
    }
};

int main() {
    return 0;
}