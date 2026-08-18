#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> numsCount;

        for (int num : nums)
            numsCount[num]++;

        if (k == n)
            return numsCount.rbegin()->first;

        else if (k == 1) {
            for (auto it = numsCount.rbegin(); it != numsCount.rend(); it++) {
                if (it->second == 1)
                    return it->first;
            }

            return -1;
        }

        int firstNumCount = numsCount[nums[0]], lastNumCount = numsCount[nums[n - 1]];        
        return max(firstNumCount == 1 ? nums[0] : -1, lastNumCount == 1 ? nums[n - 1] : -1);
    }
};

int main() {
    return 0;
}