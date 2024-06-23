#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> currSub;
        int left = 0, right = 0, maxSize = 0;
        while (right < nums.size()) {
            currSub[nums[right]]++;
            while (left <= right && currSub.rbegin()->first - currSub.begin()->first > limit) {
                currSub[nums[left]]--;
                if (!currSub[nums[left]])
                    currSub.erase(nums[left]);
                left++;
            }
            maxSize = max(maxSize, right - left + 1);
            right++;
        }
        return maxSize;
    }
};

int main(){
    vector<int> c = {4,2,2,2,4,4,2,2};
    Solution s;
    s.longestSubarray(c, 0);
    return 0;
}