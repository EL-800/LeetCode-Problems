#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int> nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> acum(n + 1);        
        for (int i = 1; i <= n; i++)
            acum[i] = acum[i - 1] + (long long)nums[i - 1];
        int left = 0, right = 0, ans = 0;
        while (right < n){
            long long currSum = acum[right + 1] - acum[left], objSum = (long long)(right - left + 1) * (long long)nums[right];
            if (currSum + k >= objSum) {
                ans = max(ans, right - left + 1);
                right++;
            }
            else
                left++;            
        }
        return ans;
    }
};

int main(){
    return 0;
}