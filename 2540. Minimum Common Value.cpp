#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {        
        int ind1 = 0, ind2 = 0;
        while (ind1 < nums1.size() && ind2 < nums2.size()){
            if (nums1[ind1] == nums2[ind2])
                return nums1[ind1];
            else if (nums1[ind1] < nums2[ind2])
                ind1++;
            else
                ind2++;
        }
        return -1;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main(){

}