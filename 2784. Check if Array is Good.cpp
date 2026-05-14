#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;

        if (n == 0)
            return false;

        sort(nums.begin(), nums.end());
        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] != i)
                return false;            
        }
        return nums[n] == nums[n - 1];
    }
};

int main() {
    return 0;
}