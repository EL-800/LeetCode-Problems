#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size() - k + 1;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] != nums[j - 1] + 1)
                    ans[i] = -1;                                       
            }
            if (ans[i] != -1)
                ans[i] = nums[i + k - 1];
        }
        return ans;
    }
};

int main() {
    return 0;
}