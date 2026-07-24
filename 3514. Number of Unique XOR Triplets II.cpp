#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size(), maxXor = 2048;

        vector<bool> pairs(maxXor);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++)
                pairs[nums[i] ^ nums[j]] = true;             
        }

        vector<bool> triplets(maxXor);
        for (int i : nums) {
            for (int j = 0; j < maxXor; j++) {
                if (pairs[j])
                    triplets[i ^ j] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < maxXor; i++) 
            ans += triplets[i];   
        
        return ans;
    }
};

int main() {
    return 0;
}