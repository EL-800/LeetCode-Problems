#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {        
        long long sum1 = 0, sum2 = 0;
        bool hasZeros1 = false, hasZeros2 = false;
        for (int num : nums1) {
            sum1 += (long long)num;
            if (!num) {
                sum1++;
                hasZeros1 = true;
            }
        }
        for (int num : nums2) {            
            sum2 += (long long)num;
            if (!num) {
                sum2++;
                hasZeros2 = true;
            }
        }
        if (sum1 < sum2 && !hasZeros1)
            return -1;
        if (sum2 < sum1 && !hasZeros2)
            return -1;
        return max(sum1, sum2);
    }
};

int main() {
    return 0;
}