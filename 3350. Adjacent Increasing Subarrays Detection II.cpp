#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int currSize = 1, n = nums.size(), prev = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                currSize++;
            else {
                prev = currSize;
                currSize = 1;                                            
            }
            if (currSize / 2 >= k || min(prev, currSize) >= k)
                return true;
        }

        return false;
    }

public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int left = 0, right = nums.size() / 2 + 2;
        while (left < right) {
            int mid = (left + right) / 2 + 1;
            if (hasIncreasingSubarrays(nums, mid))
                left = mid;
            else
                right = mid - 1;
        }
        
        return left;
    }
};

int main() {
    return 0;
}