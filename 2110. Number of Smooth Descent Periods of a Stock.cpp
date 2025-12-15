#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 1, currSize = 1;
        for (int right = 1; right < n; right++) {
            if (prices[right - 1] - 1 != prices[right]) 
                currSize = 0;      
            ans += ++currSize;                    
        }
        return ans;
    }
};

int main() {
    return 0;
}