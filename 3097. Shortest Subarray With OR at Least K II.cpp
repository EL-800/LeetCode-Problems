#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void ModifyBits(int (&activatedBits)[32], int num, int m) {
        int ind = 0;
        while (1 << ind <= num) {
            if ((1 << ind) & num)
                activatedBits[ind] += m;
            ind++;
        }
    }

    int GetBitsValue(int (&activatedBits)[32]) {
        int val = 0;
        for (int i = 0; i < 32; i++) {
            if (activatedBits[i]) 
                val += 1 << i;
        }
        return val;
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int activatedBits[32];
        int left = 0, right = 0, ans = INT_MAX;
        while (right < nums.size()) {
            ModifyBits(activatedBits, nums[right], 1);
            while (left <= right && GetBitsValue(activatedBits) >= k) {
                ans = min(ans, right - left + 1);
                ModifyBits(activatedBits, nums[left], -1);
                left++;
            }
            right++;            
        }
        return ans != INT_MAX ? ans : -1;
    }
};

int main() {
    return 0;
}