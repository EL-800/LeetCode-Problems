#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> numbersCount;
        int left = 0, right = 0;
        long long currSum = 0, ans = 0;
        while (right < k - 1) {
            currSum += nums[right];
            numbersCount[nums[right]]++;
            right++;
        }
        while (right < nums.size()) {
            currSum += nums[right];
            numbersCount[nums[right]]++;
            right++;
            if (numbersCount.size() == k)
                ans = max(ans, currSum);
            currSum -= nums[left];
            numbersCount[nums[left]]--;
            if (!numbersCount[nums[left]])
                numbersCount.erase(nums[left]);
            left++;            
        }
        return ans;
    }
};

int main() {
    return 0;
}