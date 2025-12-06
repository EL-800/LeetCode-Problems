#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int mod = 1e9 + 7;
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> currNums;
        vector<int> memo(n + 1);
        memo[0] = 1;                
        int left = 0;
        long long curr = 1;                
        for (int right = 0; right < n; right++){
            currNums.insert(nums[right]); 
            while((*currNums.rbegin()) - (*currNums.begin()) > k){
                currNums.erase(currNums.find(nums[left]));
                curr -= memo[left];
                left++;

                if (curr < 0)
                    curr += mod;
            }
            memo[right + 1] = curr % mod; 
            curr = (curr + memo[right + 1]) % mod;                        
        }
        return memo[n] % mod;
    }
};

int main() {
    return 0;
}