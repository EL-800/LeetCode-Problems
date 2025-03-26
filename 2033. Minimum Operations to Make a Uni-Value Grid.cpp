#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> nums;
            int reminder = grid[0][0] % x;
            for (auto &row : grid) {
                for (int num : row) {
                    if (num % x != reminder)
                        return -1;
                    nums.push_back(num);
                }
            }
            sort(nums.begin(), nums.end());
            int pivot = nums[nums.size() / 2], ans = 0;
            for (int num : nums)
                ans += abs(pivot - num) / x;
            return ans;
        }
    };

int main() {
    return 0;
}