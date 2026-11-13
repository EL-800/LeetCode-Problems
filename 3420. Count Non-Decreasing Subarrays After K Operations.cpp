#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), right = n - 1;
        long long ans = 0, cost = 0;        
        deque<pair<int, int>> pivots;
        for (int left = n - 1; left >= 0; left--) {
            int count = 1;
            while (!pivots.empty() && pivots.back().first < nums[left]) {                
                cost += 1ll * (nums[left] - pivots.back().first) * pivots.back().second;                
                count += pivots.back().second;
                pivots.pop_back();
            }

            pivots.push_back({nums[left], count});
            while (cost > k) {
                cost -= pivots.front().first - nums[right];
                if (pivots.front().second == 1) 
                    pivots.pop_front();                
                else 
                    pivots.front().second--;                
                right--;
            }
            
            ans += right - left + 1;
        }
        return ans;
    }
};

int main() {
    return 0;
}