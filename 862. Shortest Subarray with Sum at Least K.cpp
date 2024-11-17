#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {        
        vector<long long> prefixSum(nums.size());        
        deque<int> indexes;
        for (int i = 0; i < nums.size(); i++)
            prefixSum[i + 1] = prefixSum[i] + nums[i];                
        int ans = INT_MAX;
        for (int i = 0; i <= nums.size(); i++) {
            while (!indexes.empty() && prefixSum[i] - prefixSum[indexes.front()] >= k) {
                ans = min(ans, i - indexes.front());
                indexes.pop_front();
            }
            while (!indexes.empty() && prefixSum[i] <= prefixSum[indexes.back()]) 
                indexes.pop_back();            
            indexes.push_back(i);
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main() {
    return 0;
}