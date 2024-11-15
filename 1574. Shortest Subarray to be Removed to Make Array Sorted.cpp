#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();        
        vector<int> sortedSuffix;
        if (n == 1)
            return 1;
        int suffixInd = n - 1, next = INT_MAX;
        while (suffixInd >= 0 && arr[suffixInd] <= next) {
            next = arr[suffixInd];                       
            suffixInd--;
        }             
        sortedSuffix.assign(arr.begin() + suffixInd + 1, arr.end());                   
        for (int a : sortedSuffix)
            cout << a << " ";    
        int ans = 0, prev = 0;                                                             
        for (int i = 0; i < n && prev <= arr[i]; i++) {
            int suffixSize = sortedSuffix.end() - lower_bound(sortedSuffix.begin(), sortedSuffix.end(), arr[i]);                 
            ans = max(ans, i + 1 + suffixSize);
            prev = arr[i];
        }
        ans = max(ans, (int)sortedSuffix.size());
        return max(n - ans, 0);
    }
};

int main() {
    return 0;
}