#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> next;
        while (nums.size() > 1) {
            int n = nums.size();
            next.resize(n - 1);
            for (int i = 1; i < n; i++)                
                next[i - 1] = (nums[i] + nums[i - 1]) % 10;
            swap(nums, next);
        }
        return nums[0];
    }
};

int main() {
    return 0;
}