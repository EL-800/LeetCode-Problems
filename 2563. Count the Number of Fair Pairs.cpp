#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            auto lowInd = lower_bound(nums.begin() + i + 1, nums.end(), lower - num);
            auto upperInd = upper_bound(nums.begin() + i + 1, nums.end(), upper - num);                        
            ans += upperInd - lowInd;
        }
        return ans;
    }
};

int main() {

}