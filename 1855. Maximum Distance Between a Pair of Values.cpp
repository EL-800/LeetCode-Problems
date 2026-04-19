#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int ind1 = n - 1, ind2 = m - 1, ans = 0;

        while (ind1 >= 0 && ind2 >= 0) {
            if (ind1 > ind2) {
                ind1--;
                continue;
            }

            if (nums1[ind1] > nums2[ind2]) {
                ind2--;
                continue;
            }

            ans = max(ans, ind2 - ind1);
            ind1--;
        }

        return ans;
    }
};

int main() {
    return 0;
}