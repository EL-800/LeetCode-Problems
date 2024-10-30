#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> ascendedLis, descendedLis, lis;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            auto putLoc = lower_bound(lis.begin(), lis.end(), num);
            if (putLoc == lis.end())
                lis.push_back(num);
            else
                *putLoc = num;
            ascendedLis.push_back(lis.size());
        }     
        lis.clear();   
        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            auto putLoc = lower_bound(lis.begin(), lis.end(), num);
            if (putLoc == lis.end())
                lis.push_back(num);
            else
                *putLoc = num;
            descendedLis.push_back(lis.size());
        }
        reverse(descendedLis.begin(), descendedLis.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {  
            if (ascendedLis[i] >= 2 && descendedLis[i] >= 2)          
                ans = max(ans, ascendedLis[i] + descendedLis[i] - 1);        
        }
        return n - ans;
    }
};

int main() {
    return 0;
}