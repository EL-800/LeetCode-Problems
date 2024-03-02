#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--){
            int leftSquare = nums[left] * nums[left], rightSquare = nums[right] * nums[right];
            if (leftSquare > rightSquare) {
                ans[i] = leftSquare;
                left++;
            }
            else{
                ans[i] = rightSquare;
                right--;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}