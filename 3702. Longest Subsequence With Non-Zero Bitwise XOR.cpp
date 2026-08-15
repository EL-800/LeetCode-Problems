#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0, zeroCount = 0, n = nums.size();
        for (int num : nums) {
            totalXor ^= num;
            zeroCount += num == 0;
        }

        if (zeroCount == n)
            return 0;
        return totalXor ? n : n - 1;
    }
};

int main() {
    return 0;
}