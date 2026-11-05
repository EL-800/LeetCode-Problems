#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size(), m = arr2.size();
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        int ind1 = 0, ind2 = 0, ans = 0;
        while (ind1 < n) {                        
            while(ind2 < m && arr1[ind1] - d > arr2[ind2]) 
                ind2++;                                            
            ans += abs(arr2[ind2] - arr1[ind1]) > d;
            ind1++;
        }

        return ans;
    }
};

int main() {
    return 0;
}