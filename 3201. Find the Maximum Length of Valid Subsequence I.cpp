#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int FindLongestSequence(vector<int>& nums, vector<int> sequence) {
        int n = nums.size(), ans = 0, sInd = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == sequence[sInd]) {
                ans++;
                sInd = (sInd + 1) % sequence.size();
            }
        }
        return ans;
    }

public:
    int maximumLength(vector<int>& nums) {
        int ee = FindLongestSequence(nums, {0, 0});
        int oo = FindLongestSequence(nums, {1, 1});
        int eo = FindLongestSequence(nums, {0, 1});
        int oe = FindLongestSequence(nums, {1, 0});
        return max({ee, oo, eo, oe});
    }
};

int main() {
    return 0;
}