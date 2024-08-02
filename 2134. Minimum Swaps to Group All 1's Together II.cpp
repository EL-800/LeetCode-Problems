#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n =  nums.size(), size = count(nums.begin(), nums.end(), 1);
        for (int i = 0; i < n; i++)
            nums.push_back(nums[i]);
        n = nums.size();        
        int left = 0, right = 0, currZeros = 0;
        for (;right < size; right++) 
            currZeros += nums[right] == 0;    
        right--;
        int ans = INT_MAX;
        while (1) {            
            ans = min(ans, currZeros);
            right++;
            if (right == n)
                break;            
            currZeros += nums[right] == 0;            
            currZeros -= nums[left] == 0;
            left++;
        }
        return ans;
    }
};

int main() {
    vector <int> c = {0,1};
    Solution s;
    s.minSwaps(c);
    return 0;
}