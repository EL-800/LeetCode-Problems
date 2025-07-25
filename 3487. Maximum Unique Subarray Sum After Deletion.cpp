#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = *max_element(nums.begin(), nums.end()), curr = 0;
        unordered_set<int> seen;
        for (int num : nums) {
            if (num < 0)
                continue;
            if (seen.count(num))
                continue;
            curr += num;
            ans = max(ans, curr);
            seen.insert(num);
        }            
        return ans;
    }
};

int main() {
    return 0;
}