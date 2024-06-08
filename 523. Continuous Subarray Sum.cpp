#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        seen.reserve(nums.size());
        int currSum = 0;
        seen[0] = -1;
        for (int i = 0; i < nums.size(); i++){
            currSum = (currSum + nums[i]) % k;
            if (seen.count(currSum)){
                int diff = i - seen[currSum];
                if (diff > 1)
                    return true;                
            }
            else
                seen[currSum] = i;                
        }
        return false;
    }
};

int main(){
    return 0;
}