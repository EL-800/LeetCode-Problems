#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> reserveLeft;
        priority_queue<int, vector<int>, greater<>> removedLeft;
        multiset<int> removedRight; 
        int n = nums.size(), left = 0;
        long long removedLeftSum = 0, removedRightSum = 0, totalSumL = 0, totalSumR = 0; 

        for (; left < n / 3; left++) {          
            totalSumL += (long long)nums[left];
            reserveLeft.push(nums[left]);                
        }

        for (int i = left; i < n; i++) {
            totalSumR += (long long)nums[i];
            removedRight.insert(nums[i]);
            removedRightSum += (long long)nums[i];
            if (removedRight.size() > n / 3) {
                removedRightSum -= (long long)*removedRight.rbegin();
                removedRight.erase(prev(removedRight.end()));                
            }
        }

        long long ans = totalSumL - (totalSumR - removedRightSum);

        for (; left < 2 * (n / 3); left++) {
            totalSumL += (long long)nums[left];
            totalSumR -= (long long)nums[left];

            reserveLeft.push(nums[left]);
            removedLeftSum += (long long)reserveLeft.top();
            removedLeft.push(reserveLeft.top());
            reserveLeft.pop();
            if (removedLeft.size() > n / 3) { 
                removedLeftSum -= (long long)removedLeft.top();
                removedLeft.pop();          
            }

            if (!removedRight.empty() && removedRight.find(nums[left]) != removedRight.end()) {
                removedRightSum -= (long long)nums[left];
                removedRight.erase(removedRight.find(nums[left]));
            }
            else if (!removedRight.empty()) {
                removedRightSum -= (long long)*removedRight.rbegin();
                removedRight.erase(prev(removedRight.end()));
            }
            
            ans = min(ans, (totalSumL - removedLeftSum) - (totalSumR - removedRightSum)); 
        }
        return ans;

    }
};

int main() {
    return 0;
}