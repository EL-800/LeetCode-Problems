#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool IsPossible(vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i++;
            }
        }        
        return count >= p;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {        
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        while (left < right) {
            int mid = (left + right) / 2;
            if (IsPossible(nums, p, mid))
                right = mid;
            else
                left = mid + 1;
        } 
        return left;
    }
};

int main() {
    return 0;
}