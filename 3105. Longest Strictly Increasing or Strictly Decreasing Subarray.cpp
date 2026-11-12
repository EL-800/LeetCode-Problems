#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 1, curr = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                curr++;
            else                 
                curr = 1;
            ans = max(ans, curr);            
        }

        curr = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {                
                curr++;
            }
            else                 
                curr = 1;            
            ans = max(ans, curr);
        }

        return ans;
    }
};

int main() {
    return 0;
}