#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            unordered_map<int, int> seenValues;
            int left = 0, right = 0, n = nums.size();
            long long ans = 0, count = 0;
            while (right < n) {                
                count += seenValues[nums[right]]++;
                while (left < right && count >= k) {
                    ans += n - right;
                    count -= --seenValues[nums[left]];
                    left++;
                }
                right++;
            }
            return ans;
        }
    };

int main() {
    return 0;
}