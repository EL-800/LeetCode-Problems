#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[0])
                right = mid;
            else
                left = mid + 1;
        }

        return nums[left] < nums[0] ? nums[left] : nums[0];
    }
};

int main() {
    return 0;
}