#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int left = 0, center = 1, right = 1, ans = 0;
        while (center < nums.size() && nums[center] == nums[center - 1])
            center++;
        if (center == nums.size())
            return 0;
        right = center + 1;
        while (true) {                        
            while (right < nums.size() && nums[right] == nums[right - 1])
                right++;
            if (right == nums.size())
                break;
            if (nums[left] < nums[center] && nums[right] < nums[center])
                ans++;
            else if (nums[left] > nums[center] && nums[right] > nums[center])
                ans++;
            left = center;
            center = right;
            right++;                        
        }
        return ans;
    }
};

int main() {
    return 0;
}