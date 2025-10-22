#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {        
        map<int, int> freqCountSum;        

        for (int num : nums)
            freqCountSum[num]++;
        for (auto it = next(freqCountSum.begin()); it != freqCountSum.end(); it++) 
            it->second += prev(it)->second;    
        freqCountSum[0] = 0;    

        int ans = 0;
        for (auto it = next(freqCountSum.begin()); it != freqCountSum.end(); it++) {
            int x = it->second - prev(it)->second;
            auto left = prev(freqCountSum.lower_bound(it->first - k));            
            auto right = prev(freqCountSum.upper_bound(it->first + k));
            int count = right->second - left->second;
            ans = max(ans, x + min(count - x, numOperations));
        }        
        
        sort(nums.begin(), nums.end());
        int left = 0, n = nums.size();
        for (int right = 0; right < n; right++) {
            while (left <= right && nums[right] - nums[left] > 2 * k) 
                left++;
            int count = right - left + 1;
            ans = max(ans, min(count, numOperations));
        }
        
        return ans;
    }
};

int main() {
    vector<int> c = {2,33};
    Solution s;
    cout << s.maxFrequency(c, 50, 0);
    return 0;
}