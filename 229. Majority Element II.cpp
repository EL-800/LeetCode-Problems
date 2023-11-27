#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int num : nums)
            counts[num]++;
        int obj = nums.size() / 3;
        vector<int> ans;
        for (auto p : counts){
            if (p.second > obj)
                ans.push_back(p.first);
        }
        return ans;
    }
};

int main(){
    return 0;
}