#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), curr = n;
        long long sum = 0, ans = 0;
        unordered_map<int, int> prefixSum;

        prefixSum[n] = 1;
        for (int num : nums) {
            if (num == target) {
                sum += prefixSum[curr];
                curr++;
                prefixSum[curr]++;
            } 
            else {
                curr--;
                sum -= prefixSum[curr];
                prefixSum[curr]++;
            }
            ans += sum;
        }

        return ans;
    }
};

int main() {
    return 0;
}