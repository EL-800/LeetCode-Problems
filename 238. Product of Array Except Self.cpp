#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefixProduct =  1, suffixProduct = 1, n = nums.size();
        vector<int> products(n, 1);
        for (int i = 0; i < n; i++){
            products[i] *= prefixProduct;
            products[n - i - 1] *= suffixProduct;
            prefixProduct *= nums[i];
            suffixProduct *= nums[n - i - 1];
        }
        return products;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main(){
    return 0;
}