#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        multiset<int> dp;
        queue<multiset<int>::iterator> iterators;        
        for (int i = 0; i < nums.size(); i++){
            if (dp.empty()) {
                dp.insert(nums[i]);
                continue;
            }
            int aux = nums[i] + *dp.rbegin();
            auto curr = dp.insert(max(nums[i], nums[i] + *dp.rbegin()));
            iterators.push(curr);
            if (dp.size() > k) {
                dp.erase(iterators.front());
                iterators.pop();
            }
        }
        return *dp.rbegin();
    }
};

int main(){
    vector<int> a = {10,2,-10,5,20};
    Solution s;
    cout << s.constrainedSubsetSum(a, 2);
    return 0;
}