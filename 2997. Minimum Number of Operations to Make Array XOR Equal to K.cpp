#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorCalc = 0;
        for (int num : nums)
            xorCalc ^= num;         
        int bit = 1, diff = 0;
        while (bit <= max(k, xorCalc)){
            if (xorCalc & bit != k & bit)
                diff++;
            bit <<= 1;
        }
        return diff;
    }
};

int main(){
    return 0;
}