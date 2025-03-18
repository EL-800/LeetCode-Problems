#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int currMask = 0, left = 0, right = 0, ans = 1;
            while (right < nums.size()) {
                while (left < right && currMask & nums[right]) {
                    currMask ^= nums[left];
                    left++;
                }
                currMask |= nums[right];
                ans = max(ans, right - left + 1);                
                right++;                
            }
            return ans;
        }
    };

int main() {
    return 0;
}