#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {        
        int ans = abs(nums[0] - nums.back()), n = nums.size();
        for (int i = 1; i < n; i++){
            ans = max(ans, abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
};

int main() {
    return 0;
}