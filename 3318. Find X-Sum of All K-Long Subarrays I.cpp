#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size(), left = 0, right = 0;
        unordered_map<int, int> freqCount;
        for (right = 0; right < k - 1; right++)
            freqCount[nums[right]]++;
        
        vector<int> ans;
        for (; right < n; right++) {
            freqCount[nums[right]]++;
            int currSum = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> greatests;
            for (auto [key, val] : freqCount) {
                greatests.push({val, key});
                currSum += val * key;
                if (greatests.size() > x) {                    
                    currSum -= greatests.top().first * greatests.top().second;
                    greatests.pop();
                }
            }      
            ans.push_back(currSum);          
            freqCount[nums[left]]--;
            left++;
        }

        return ans;
    }
};

int main() {
    vector<int> c = {1,1,2,2,3,4,2,3};
    Solution s;
    s.findXSum(c, 6, 2);
    return 0;
}