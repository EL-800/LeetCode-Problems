#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int lastSegmentMax = 0, currSegmentMax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (__builtin_popcount(nums[i - 1]) != __builtin_popcount(nums[i])) {
                lastSegmentMax = currSegmentMax;
                currSegmentMax = nums[i];
            }
            else
                currSegmentMax = max(currSegmentMax, nums[i]);
            if (nums[i] < lastSegmentMax)
                return false;
        }
        return true;
    }
};

int main() {
    return 0;
}