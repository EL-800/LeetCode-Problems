#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int result = 0;
        vector<unordered_map<long long,int>> dp(n);        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                long long d = (long long)A[j] - A[i];
                dp[j][d]++;
                if (dp[i].find(d) != dp[i].end()) {
                    dp[j][d] += dp[i][d];
                    result += dp[i][d];
                }
            }
        }        
        return result;
    }
};

int main(){
    return 0;
}