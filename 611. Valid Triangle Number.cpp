#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0, n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int k = upper_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j] - 1) - nums.begin();
                count += k - j - 1;
            }
        }

        return count;
    }
};

int main() {
    return 0;
}