#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size(), i = 1, sum = nums[0];
        unordered_set<int> bucket;

        if (n == 1)
            return nums[0] + 1;

        if (nums[1] == nums[0] + 1) {
            for (; i < n && nums[i - 1] + 1 == nums[i]; i++) {
                sum += nums[i];                    
            }
        }
        else {
            bucket.insert(nums[0]);
            sum = nums[0];
        }

        for (; i < n; i++) 
            bucket.insert(nums[i]);        
        
        while (bucket.count(sum)) 
            sum++;
        
        return sum;
    }
};

int main() {
    return 0;
}