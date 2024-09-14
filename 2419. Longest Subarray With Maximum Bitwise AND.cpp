#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxE = *max_element(nums.begin(), nums.end());
        int left = 0, right = 0, ans = 0;
        while(right < nums.size()) {
            if (nums[left] != nums[right] || nums[left] != maxE)
                left = right;
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};

int main() {
    return 0;
}