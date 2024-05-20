#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int Search(vector<int>& nums, int ind = 0, int total = 0){
        if (ind == nums.size())
            return total;
        return Search(nums, ind + 1, total ^ nums[ind]) + Search(nums, ind + 1, total);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        return Search(nums);
    }
};

int main(){
    return 0;
}