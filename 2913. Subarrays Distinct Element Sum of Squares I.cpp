#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> countDistinct;
            for (int j = i; j < n; j++) {
                countDistinct.insert(nums[j]);
                ans += countDistinct.size() * countDistinct.size();
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}