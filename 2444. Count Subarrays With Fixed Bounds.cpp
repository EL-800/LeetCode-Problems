#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = (int)nums.size(), lastMin = -1, lastMax = -1, subStart = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                lastMin = -1;
                lastMax = -1;
                subStart = i + 1;
                continue;
            }
            if (nums[i] == minK)
                lastMin = i;
            if (nums[i] == maxK)
                lastMax = i;
            if (lastMin != -1 && lastMax != -1) {
                int last = min(lastMax, lastMin);
                ans += (long long)(last - subStart + 1);
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}