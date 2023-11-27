#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int> nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, maxi = 0;
        while (left < right)
            maxi = max(nums[left++] + nums[right--], maxi);
        return maxi;
    }
};

int main(){
    return 0;
}