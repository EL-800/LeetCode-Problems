#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n = nums.size(), ans = 0;
            for (int i = 0; i < n - 2; i++) {
                if (nums[i])
                    continue;
                ans++;
                for (int j = i; j < i + 3; j++) 
                    nums[j] ^= 1;                                    
            }
            return nums[n - 1] && nums[n - 2] ? ans : -1;
        }
    };

int main() {
    return 0;
}