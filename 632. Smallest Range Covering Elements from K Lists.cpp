#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        if (k == 1)
            return {nums[0][0], nums[0][0]};
        vector<pair<int, int>> merged;
        for (int i = 0; i < k; i++) {
            for (int num : nums[i])
                merged.push_back({num, i});
        }
        sort(merged.begin(), merged.end());
        unordered_map<int, int> setCount;
        int left = 0, right = 0, bestLeft = 0, bestRight = 0, range = INT_MAX;
        while (right < merged.size()) {            
            setCount[merged[right].second]++;
            while (left < right && setCount.size() == k) {
                int currRange = merged[right].first - merged[left].first;
                if (currRange < range) {
                    bestLeft = merged[left].first;
                    bestRight = merged[right].first;
                    range = currRange;
                }                
                if (!--setCount[merged[left].second])
                    setCount.erase(merged[left].second);
                left++;
            }
            right++;
        }
        return {bestLeft, bestRight};
    }
};

int main() {
    return 0;
}