#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 0; i <= 3; i++) { 
            int j = nums.size() - (3 - i + 1);
            ans = min(ans, nums[j] - nums[i]);                                    
        }        
        return ans;
    }
};

int main() {
    return 0;
}