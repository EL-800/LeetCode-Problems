#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
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
};

int main() {
    return 0;
}