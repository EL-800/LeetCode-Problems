#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int left = start, right = start;
        while (left >= 0 || right <= nums.size()) {
            if (left >= 0) {
                if (nums[left] == target)
                    return start - left;
                left--;
            }          
            if (right <= nums.size()) {
                if (nums[right] == target)
                    return right - start;
                right++;
            }      
        }

        return 800;
    }
};

int main() {
    return 0;
}