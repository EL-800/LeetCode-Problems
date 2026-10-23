#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size(), k = -1;
        for (int i = 0; i < n; i++) {
            if (i != nums[i])
                k &= nums[i];            
        }
        return max(k, 0);
    }
};

int main() {
    return 0;
}