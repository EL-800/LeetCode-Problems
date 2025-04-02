#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long maxValue = 0, maxDiff = 0, ans = 0;
            for (int i = 0; i < nums.size(); i++) {
                long long curr = nums[i];
                ans = max(ans, maxDiff * curr);
                maxDiff = max(maxDiff, maxValue - curr);
                maxValue = max(maxValue, curr);                
            }
            return ans;
        }
    };

int main() {
    return 0;
}