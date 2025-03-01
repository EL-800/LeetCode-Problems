#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size();
            for (int i = 0; i < n - 1; i++) {
                if (nums[i] == nums[i + 1]) {
                    nums[i] *= 2;
                    nums[i + 1] = 0;
                }
            }
            int zeroCount = count(nums.begin(), nums.end(), 0);
            vector<int> ans;
            for (int i = 0; i < n; i++) {
                if (nums[i])
                    ans.push_back(nums[i]);
            }
            ans.insert(ans.end(), zeroCount, 0);
            return ans;
        }
    };

int main() {
    return 0;
}