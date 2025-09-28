#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int n = (int)nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] - nums[i + 1] < nums[i + 2])
                return nums[i] + nums[i + 1] + nums[i + 2];
        }
        return 0;
    }
};

int main() {
    return 0;
}