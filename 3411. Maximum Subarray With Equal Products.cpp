#include <bits/stdc++.h>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for (int i = 0; i < n; i++) {
            int totalProd = 1, currGCD = nums[i], currLCM = nums[i];
            for (int j = i; j < n; j++) {
                totalProd *= nums[j];
                currGCD = gcd(currGCD, nums[j]);
                currLCM = lcm(currLCM, nums[j]);
                if (currLCM * currGCD == totalProd)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}