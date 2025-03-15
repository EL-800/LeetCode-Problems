#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        bool IsPossible(vector<int>& nums, int k, int maxVal) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= maxVal) {
                    k--;
                    i++;
                }                
            }    
            return k <= 0;        
        }

    public:
        int minCapability(vector<int>& nums, int k) {
            int left = *min_element(nums.begin(), nums.end()), right = *max_element(nums.begin(), nums.end());
            while (left < right) {
                int mid = (left + right) / 2;
                if (IsPossible(nums, k, mid)) 
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