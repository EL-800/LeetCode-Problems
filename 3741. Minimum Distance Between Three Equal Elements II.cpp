#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mappedInd;
        for (int i = 0; i < n; i++) 
            mappedInd[nums[i]].push_back(i);        

        int ans = INT_MAX;        
        for (auto [val, inds] : mappedInd) {                            
            for (int left = 0, right = 2; right < inds.size(); left++, right++)
                ans = min(ans, 2 * (inds[right] - inds[left]));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    return 0;
}