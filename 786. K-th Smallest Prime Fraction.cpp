#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<tuple<double, int, int>> fractionValues;
        for (int i = 0; i < n - 1; i++){
            for (int j = i + 1; j < n ; j++){
                fractionValues.push_back(make_tuple((double)arr[i] / (double)arr[j], arr[i], arr[j]));
            }
        }            
        sort(fractionValues.begin(), fractionValues.end());        
        auto kthValue = fractionValues[k - 1];        
        return { get<1>(kthValue), get<2>(kthValue) };
    }
};

int main(){
    vector<int> c = {1,2,3,5};
    Solution s;
    s.kthSmallestPrimeFraction(c, 3);
    return 0;
}