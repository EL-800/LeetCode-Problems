#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(nums);

        for (int i = 1; i < n; i++) 
            prefixSum[i] += prefixSum[i - 1]; 

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int left = prefixSum[i], right = prefixSum[n - 1] - prefixSum[i];
            if (nums[i])
                continue;
            if (right - left == 0)
                ans += 2;
            if (abs(right - left) == 1)
                ans++;
        }     
        return ans;
    }
};

int main() {
    return 0;
}