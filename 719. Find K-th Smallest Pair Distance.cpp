#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int CountDistances(vector<int>& nums, int threshold) {
        int left = 0, right = 0, count = 0;
        while (right < nums.size()) {
            while (right > left && nums[right] - nums[left] > threshold) 
                left++;            
            count += right - left;
            right++;
        }
        return count;
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = *nums.rbegin() - *nums.begin();
        while(left < right) {
            int mid = (left + right) / 2;
            if (CountDistances(nums, mid) < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

int main() {
    return 0;
}