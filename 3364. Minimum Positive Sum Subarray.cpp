#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), ans = INT_MAX;
        for (int size = l; size <= r && size <= n; size++) {
            int left = 0, right = 0, sum = 0;
            for (; right < size; right++)
                sum += nums[right];

            if (sum > 0)
                ans = min(ans, sum);
                
            for (; right < n; right++, left++) {
                sum += nums[right];
                sum -= nums[left];
                if (sum > 0)
                    ans = min(ans, sum);
            }                
        }

        return ans != INT_MAX ? ans : -1;
    }
};

int main() {
    return 0;
}