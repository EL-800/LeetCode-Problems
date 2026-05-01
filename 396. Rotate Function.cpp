#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), totalSum = 0, f = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
            f += i * nums[i];
        }
        
        int ans = f;
        for (int i = 1; i < n; i++) {
            f += totalSum - n * nums[n - i];
            ans = max(ans, f);
        }

        return ans;
    }
};

int main() {
    return 0;
}