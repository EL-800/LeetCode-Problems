#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int maxOr = 0;

    int CountAll(vector<int>& nums, int ind = 0, int currOr = 0) {
        if (ind == nums.size())
            return currOr == maxOr;
        return CountAll(nums, ind + 1, currOr | nums[ind]) + CountAll(nums, ind + 1, currOr);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {        
        for (int num : nums) 
            maxOr |= num;    
        return CountAll(nums);
    }
};

int main() {
    return 0;
}