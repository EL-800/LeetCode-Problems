#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool Validation(vector<int>& nums, int validate, bool strict = false){
        int count = 0;
        for (int num : nums){
            if (num >= validate)
                count++;
        }
        if (strict)
            return count == validate;
        return count >= validate;
    }

public:
    int specialArray(vector<int>& nums) {
        int left = 0, right = *max_element(nums.begin(), nums.end());
        while (left < right){
            int mid = (left + right) / 2 + 1;
            if (Validation(nums, mid))
                left = mid;
            else
                right = mid - 1;
        }
        return Validation(nums, left, true) ? left : -1;
    }
};

int main(){
    return 0;
}