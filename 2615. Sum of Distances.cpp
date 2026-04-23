#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<long long>> groupedNums;

        for (int i = 0; i < n; i++) 
            groupedNums[nums[i]].push_back(i);

        vector<long long> ans(n);
        for (auto [val, indSet] : groupedNums) {            
            long long cSize = indSet.size(), sum = 0;
            
            for (long long i = 0; i < cSize; i++) {
                long long diff = indSet[i] * i - sum;
                sum += indSet[i];
                ans[indSet[i]] += diff;
            }

            sum = 0;
            for (int i = cSize - 1; i >= 0; i--) {
                long long diff = sum - indSet[i] * (cSize - i - 1);
                sum += indSet[i];
                ans[indSet[i]] += diff;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}