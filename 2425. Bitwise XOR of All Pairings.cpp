#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), ans = 0;
        if (m % 2) {
            for (int num : nums1) 
                ans ^= num;            
        }
        if (n % 2) {
            for (int num : nums2) 
                ans ^= num;     
        }
        return ans;
    }
};

int main() {
    return 0;
}