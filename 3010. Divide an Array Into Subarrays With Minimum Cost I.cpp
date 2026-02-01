#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        priority_queue<int> lowests;
        int limit = 2;
        for (int i = 1; i < nums.size(); i++) {
            lowests.push(nums[i]);
            if (lowests.size() > limit)
                lowests.pop();
        }            
        
        int sum = 0;
        while (!lowests.empty()) {
            sum += lowests.top();
            lowests.pop();            
        }

        return sum + nums[0];
    }
};

int main() {
    return 0;
}