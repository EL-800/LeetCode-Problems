#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> bucket;
        for (int num : arr1)
            bucket[num]++;
        vector<int> ans;
        for (int num : arr2){
            while (bucket[num]--)
                ans.push_back(num);                                        
        }
        for (auto ind = bucket.begin(); ind != bucket.end(); ind++){
            auto [key, val] = *ind;
            while (val-- > 0)
                ans.push_back(key);
        }
        return ans;
    }
};

int main(){
    vector<int> a1 = {2,3,1,3,2,4,6,7,9,2,19}, a2 = {2,1,4,3,9,6};
    Solution s;
    s.relativeSortArray(a1, a2);
    return 0;
}