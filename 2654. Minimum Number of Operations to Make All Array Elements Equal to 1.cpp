#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones)
            return n - ones;

        int minSize = INT_MAX;        
        for (int i = 0; i < n; i++) {
            int currGCD = nums[i];            
            for (int j = i + 1; j < n; j++) {
                currGCD = __gcd(currGCD, nums[j]);                
                if (currGCD == 1) {
                    minSize = min(j - i + 1, minSize);
                    break;
                }
            }
        }
        if (minSize == INT_MAX)
            return -1;
        return minSize - 2 + n;
    }
};

int main() {
    return 0;
}