#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        for (int num : nums){
            auto ind = lower_bound(LIS.begin(), LIS.end(), num);
            if (ind == LIS.end())
                LIS.push_back(num);
            else
                *ind = num;
        }
        return LIS.size();
    }
};

int main(){
    return 0;
}