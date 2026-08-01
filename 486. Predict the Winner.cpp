#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int FindMax(vector<int>& nums, int left, int right) {
        if (left == right)
            return nums[left];
        return max(nums[left] - FindMax(nums, left + 1, right), nums[right] - FindMax(nums, left, right - 1));
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return FindMax(nums, 0, n - 1) >= 0;
    }
};

int main() {
    return 0;
}