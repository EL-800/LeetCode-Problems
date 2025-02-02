#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), drops = nums[0] < nums[n - 1];     
        for (int i = 1; i < n; i++)
            drops += nums[i] < nums[i - 1];
        return drops <= 1;
    }
};

int main() {
    return 0;
}