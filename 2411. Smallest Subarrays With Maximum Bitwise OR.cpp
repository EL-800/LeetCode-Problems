#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> lastBitIndex(32), ans(n);
        for(int i = n - 1; i >= 0; i--) {
            int bitInd = 0;
            while ((1 << bitInd) <= nums[i]) {
                if ((1 << bitInd) & nums[i])
                    lastBitIndex[bitInd] = i;
                bitInd++;
            } 
            int lastInd = *max_element(lastBitIndex.begin(), lastBitIndex.end());
            ans[i] = max(lastInd - i + 1, 1);
        }
        return ans;        
    }
};

int main() {
    return 0;
}