#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> bucket;
        for (int num : nums1)
            bucket.insert(num);        
        vector<int> intersectionArray;
        for (int num : nums2){
            if (bucket.count(num)) {
                intersectionArray.push_back(num);
                bucket.erase(num);
            }
        }
        return intersectionArray;        
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