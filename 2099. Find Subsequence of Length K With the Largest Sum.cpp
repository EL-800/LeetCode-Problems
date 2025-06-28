#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> greatests;
        for (int i = 0; i < n; i++) {
            greatests.push({nums[i], i});
            if (greatests.size() > k)
                greatests.pop();
        }

        vector<int> sortedInd;
        while (!greatests.empty()) {
            sortedInd.push_back(greatests.top().second);        
            greatests.pop();
        }
        sort(sortedInd.begin(), sortedInd.end());

        vector<int> ans;
        for (int ind : sortedInd) 
            ans.push_back(nums[ind]);
        return ans;        
    }
};

int main() {
    return 0;
}