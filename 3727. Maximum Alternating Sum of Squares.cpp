#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int &num : nums) {
            if (num < 0)
                num *= -1;
        }
        
        sort(nums.rbegin(), nums.rend());
        int left = 0, right = n - 1;
        long long ans = 0ll;
        while (left < right) {
            ans += 1ll * nums[left] * nums[left] - 1ll * nums[right] * nums[right];
            left++;
            right--;
        }

        return ans + (left == right ? 1ll * nums[left] * nums[left] : 0);
    }
};

int main() {
    return 0;
}