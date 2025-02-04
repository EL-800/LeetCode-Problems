#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int last = 0, n = nums.size(), ans = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            if (last >= nums[i]) 
                curr = 0;        
            curr += nums[i];
            ans = max(ans, curr);
            last = nums[i];    
        }
        return ans;
    }
};

int main() {
    return 0;
}