#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), countAsc = 1, countDesc = 1;
        for (int i = 1; i < n; i++) {
            countAsc += nums[i] == (nums[i - 1] + 1) % n;
            countDesc += (nums[i] + 1) % n == (nums[i - 1]);
        }

        if (countAsc == n) {
            if (!nums[0])
                return 0;
            return min(n - nums[0], nums[0] + 2);
        }
        if(countDesc == n) 
            return min(n - nums[n - 1], nums[n - 1]) + 1;        
        
        return -1;
    }
};

int main() {
    return 0;
}