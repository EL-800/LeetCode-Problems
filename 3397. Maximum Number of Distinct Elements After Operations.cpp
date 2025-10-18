#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        nums[0] -= k;

        for (int i = 1; i < n; i++) {
            int newVal = max(nums[i] - k, nums[i - 1] + 1);
            nums[i] = min(newVal, nums[i] + k);
        }  
        
        unordered_set<int> elements(nums.begin(), nums.end());
        return elements.size();         
    }
};

int main() {
    return 0;
}