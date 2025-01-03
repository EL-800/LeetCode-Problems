#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {        
        long long start = 0, rightSum = accumulate(nums.begin(), nums.end(), start), leftSum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            long long num = nums[i];
            rightSum -= num;
            leftSum += num;
            ans += leftSum >= rightSum;
        }
        return ans;
    }
};

int main() {
    return 0;
}