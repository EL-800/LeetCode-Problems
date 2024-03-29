#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0, currCount = 0, n = nums.size(), maxElement = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        while (right < n) {
            currCount += nums[right] == maxElement;
            while (left < right && currCount >= k) {
                ans += (n - right);
                currCount -= nums[left] == maxElement;
                left++;
            }            
            right++;
        }
        return ans;
    }
};

int main(){
    return 0;
}