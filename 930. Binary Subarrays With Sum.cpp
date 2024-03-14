#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), prefixSum = 0, ans = 0;        
        unordered_map<int, int> prevSums;
        prevSums[0] = 1;
        for (int num : nums) {
            prefixSum += num;
            ans += prevSums[prefixSum - goal];
            prevSums[prefixSum]++;            
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main(){
    return 0;
}