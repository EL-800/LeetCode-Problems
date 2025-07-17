#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int maximumLengthObj(vector<int>& nums, int k, int obj) {
        vector<int> modFound(k);
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            if (obj - (nums[i] % k) >= 0)                    
                ans = max(modFound[nums[i] % k] = modFound[obj - (nums[i] % k)] + 1, ans);                                                         
            else
                ans = max(modFound[nums[i] % k] = modFound[(obj - (nums[i] % k) + k) % k] + 1, ans);     
        }           
        return ans;
    }

public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) 
            nums[i] %= k;        
        int ans = 0;
        for (int i = 0; i < k; i++) 
            ans = max(maximumLengthObj(nums, k, i), ans);  
        return ans;      
    }
};

int main() {
    return 0;
}