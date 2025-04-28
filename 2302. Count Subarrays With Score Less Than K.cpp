#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            int n = nums.size();
            vector<long> prefixSum(n + 1);
            for (int i = 1; i <= n; i++) 
                prefixSum[i] += prefixSum[i - 1] + nums[i - 1];
            long long ans = 0ll;
            for (long i = 1; i <= n; i++) {
                long left = i - 1, right = n;
                while (left < right) {
                    long mid = (left + right) / 2 + 1;
                    if ((prefixSum[mid] - prefixSum[i - 1]) * (mid - i + 1) < k)
                        left = mid;
                    else
                        right = mid - 1;
                }
                ans += right - i + 1;
            }
            return ans;                
        }
    };

int main() {
    return 0;
}