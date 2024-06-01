#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int totalXor = 0;
        for (int num : nums)
            totalXor ^= num;
        unsigned int LSB = totalXor & -(unsigned int)totalXor;
        vector<int> ans(2, 0);
        for (int num : nums){
            if ((LSB & num) == 0)
                ans[0] ^= num;
            else
                ans[1] ^= num;
        }
        return ans;
    }
};

int main(){
    return 0;
}