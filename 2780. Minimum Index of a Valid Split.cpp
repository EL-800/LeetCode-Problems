#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            unordered_map<int, int> frequency;
            for (int num : nums)
                frequency[num]++;
            auto [dominant, rightCount] = *max_element(frequency.begin(), frequency.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;
            });
            int leftCount = 0, n = nums.size();
            for (int i = 0; i < n; i++) {
                leftCount += nums[i] == dominant;
                rightCount -= nums[i] == dominant;
                if (leftCount > i / 2 + 1 && rightCount > (n - i) / 2)
                    return i;
            }
            return -1;
        }
    };

int main() {
    return 0;
}