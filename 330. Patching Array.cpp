#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 1;
        int ind = 0, ans = 0;
        while (sum <= n){
            if (ind < nums.size() && nums[ind] <= sum){
                sum += nums[ind];
                ind++;
            }
            else{
                sum *= 2;
                ans++;
            }
        }
        return ans;        
    }
};

int main(){
    return 0;
}