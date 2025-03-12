#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int negativeCount = 0, positiveCount = 0;
            for (int num : nums) {
                if (num < 0)
                    negativeCount++;
                else if (num > 0)
                    positiveCount++;
            }
            return max(negativeCount, positiveCount);
        }
    };

int main() {
    return 0;
}