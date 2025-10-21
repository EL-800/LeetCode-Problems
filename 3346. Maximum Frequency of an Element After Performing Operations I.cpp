#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mE = *max_element(nums.begin(), nums.end());
        vector<int> freqCountSum(mE + 1);

        for (int num : nums)
            freqCountSum[num]++;
        for (int i = 1; i <= mE; i++) 
            freqCountSum[i] += freqCountSum[i - 1];        

        int ans = 0, n = nums.size();
        for (int i = 1; i <= mE; i++) {
            int left = max(1, i - k), right = min(mE, i + k), pivot = freqCountSum[i] - freqCountSum[i - 1];
            int count = freqCountSum[right] - freqCountSum[left - 1];
            ans = max(ans, pivot + min(count - pivot, numOperations));
        }            
        
        return ans;
    }
};

int main() {
    vector<int> c = {1,4,5};
    Solution s;
    cout << s.maxFrequency(c, 1, 2);
    return 0;
}