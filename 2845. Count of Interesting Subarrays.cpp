#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            int n = nums.size();
            vector<int> prefixCount(n + 1);            
            for (int i = 1; i <= n; i++)
                prefixCount[i] = prefixCount[i - 1] + ((nums[i - 1] % modulo) == k);
            long long ans = 0;
            unordered_map<int, int> seenValues;
            seenValues[0] = 1;            
            for (int i = 1; i <= n; i++) {
                ans += seenValues[(prefixCount[i] + modulo - k) % modulo];
                seenValues[prefixCount[i] % modulo]++;
            } 
            return ans;
        }
    };

int main() {
    return 0;
}