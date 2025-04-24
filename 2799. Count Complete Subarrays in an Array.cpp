#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int n = nums.size();
            unordered_map<int, int> numsCount;
            for (int num : nums)
                numsCount[num]++;
            int objCount = numsCount.size(), left = 0, right = 0, ans = 0;
            numsCount.clear();            
            while (right < n) {
                numsCount[nums[right]]++;
                while (left < right && numsCount.size() == objCount) {
                    ans += n - right;
                    numsCount[nums[left]]--;
                    if (!numsCount[nums[left]])
                        numsCount.erase(nums[left]);
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