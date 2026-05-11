#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            while (nums[i]) {                
                ans.push_back(nums[i] % 10);
                nums[i] /= 10;
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    return 0;
}