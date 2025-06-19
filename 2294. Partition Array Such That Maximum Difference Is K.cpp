#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int beg = nums[0], n = nums.size(), ans = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - beg > k) {
                ans++;
                beg = nums[i];                
            }            
        }
        return ans + 1;
    }
};

int main() {
    return 0;
}