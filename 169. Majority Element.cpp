#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currMax = 0, countMax = 0;
        for (int num : nums){
            if (!countMax)
                currMax = num;
            countMax += currMax == num ? 1 : -1;
        }
        return currMax;
    }
};

int main(){
    return 0;
}