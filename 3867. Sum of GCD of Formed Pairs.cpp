#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(), currMax = 0;
        vector<int> prefixGcd(n);
        for (int i = 0; i < n; i++) {
            currMax = max(currMax, nums[i]);
            prefixGcd[i] = __gcd(currMax, nums[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int left = 0, right = n - 1;
        long long ans = 0;
        while (left < right) {
            ans += __gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return ans;
    }
};

int main() {
    return 0;
}