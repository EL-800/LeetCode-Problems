#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        set<pair<int, int>> pendingNums;        
        for (int i = 0; i < n; i++)
            pendingNums.insert({nums[i], i});        
        while (!pendingNums.empty()) {
            auto [val, ind] = *pendingNums.begin();            
            pendingNums.erase(pendingNums.begin());
            ans += val;
            if (ind)
                pendingNums.erase({nums[ind - 1], ind - 1});
            if (ind < n - 1)
                pendingNums.erase({nums[ind + 1], ind + 1});
        }
        return ans;
    }
};

int main() {
    return 0;
}