#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int curr = 0, ans = 0, i = 0, j = 0, n = (int)nums.size();
        vector<bool> have(*max_element(nums.begin(), nums.end()) + 1);
        while (j < n) {
            if (!have[nums[j]]) {
                curr += nums[j];
                have[nums[j]] = true;
                j++;
            }
            else {
                curr -= nums[i];
                have[nums[i]] = false;
                i++;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};

int main() {
    return 0;
}