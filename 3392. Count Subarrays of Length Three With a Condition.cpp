#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int n = nums.size(), ans = 0;
            for (int i = 0; i < n - 2; i++) 
                ans += nums[i + 1] % 2 == 0 && (nums[i] + nums[i + 2]) == nums[i + 1] / 2;  
            return ans;          
        }
    };

int main() {
    return 0;
}