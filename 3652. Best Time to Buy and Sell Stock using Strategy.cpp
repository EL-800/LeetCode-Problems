#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();                 
        vector<long long> prefixSum(n + 1);          

        for (int i = 0; i < n; i++)
            prefixSum[i + 1] = prefixSum[i] + prices[i]; 

        long long left = 0, right = 0;      
        for (int i = 0; i < n; i++) 
            right +=  prices[i] * strategy[i]; 
        
        long long ans = right;            
        for (int i = 0; i < k; i++) 
            right -= prices[i] * strategy[i]; 

        for (int i = 0; i < n - k + 1; i++) {
            int midBeg = i + k / 2, midEnd = i + k;
            long long midSum = prefixSum[midEnd] - prefixSum[midBeg];
            ans = max(ans, left + midSum + right);
            left += prices[i] * strategy[i];
            if (i != n - k)                
                right -= prices[i + k] * strategy[i + k];
        }

        return ans;
    }
};

int main() {
    return 0;
}