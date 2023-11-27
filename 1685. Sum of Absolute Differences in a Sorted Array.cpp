#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(), leftSum = 0, rightSum = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++){            
            ans[i] += i * nums[i] - leftSum;
            ans[n - i - 1] +=  rightSum - i * nums[n - i - 1];
            leftSum += nums[i];
            rightSum += nums[n - i - 1];
        }        
        return ans;
    }
};

int main(){
    return 0;
}