#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> productCount;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) 
                productCount[nums[i] * nums[j]]++;            
        }
        int ans = 0;
        for (auto [key, val] : productCount)
            ans += val * (val - 1) / 2 * 8;        
        return ans;
    }
};

int main() {
    return 0;
}