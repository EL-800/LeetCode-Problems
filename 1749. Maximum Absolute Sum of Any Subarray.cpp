#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int maxSum = 0, minSum = INT_MAX, currMax = 0, currMin = 0;
            for (int num : nums) {
                currMax += num;
                currMin += num;
                if (currMax < 0)
                    currMax = 0;
                if (currMin > 0)
                    currMin = 0;
                maxSum = max(currMax, maxSum);
                minSum = min(currMin, minSum);
            }
            return max(maxSum, -minSum);
        }
    };

int main() {
    return 0;
}