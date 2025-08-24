#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1)
            return 0;
        vector<int> fordward(n);
        vector<int> backward(n);
        fordward[0] += nums[0];
        backward[n - 1] += nums[n - 1];
        for (int i = 1; i < n; i++) {
            if (nums[i])
                fordward[i] += fordward[i - 1] + 1;            
            if (nums[n - i - 1])
                backward[n - i - 1] += backward[n - i] + 1;
        }
        int best = max(backward[1], fordward[n - 2]);
        for (int i = 1; i < n - 1; i++) 
            best = max(best, fordward[i - 1] + backward[i + 1]);        
        return best;

    }
};

int main() {
    return 0;
}