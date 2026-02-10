#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_set<int> evens, odds;

        for (int i = 0; i < n; i++) {
            evens.clear();
            odds.clear();
            for (int j = i; j < n; j++) {
                if (nums[j] % 2)
                    odds.insert(nums[j]);
                else
                    evens.insert(nums[j]);
                
                if (odds.size() == evens.size())
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}