#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long mod = 1e9 + 7;
        int n = s.size(), m = queries.size();                

        vector<long long> prefixSum(n + 1, 0), prefixNum(n + 1, 0), prefixSize(n + 1, 0), powers(n + 1, 1);                    

        for(int i = 1; i <= n; i++) 
            powers[i] = (powers[i - 1] * 10) % mod;        

        for(int i = 0; i < n; i++){
            int d = s[i] - '0';
            prefixSize[i + 1] = prefixSize[i] + (d != 0);
            prefixSum[i + 1] = prefixSum[i] + d;            

            if(d)                
                prefixNum[i + 1] = (prefixNum[i] * 10 + d) % mod;
            else
                prefixNum[i + 1] = prefixNum[i];                        
        }

        vector<int> ans(m);

        for(int i = 0; i < m; i++){
            int left = queries[i][0], right = queries[i][1], size = prefixSize[right + 1] - prefixSize[left];                        

            long long leftNum = prefixNum[left], rightNum = prefixNum[right + 1];            

            long long x = (rightNum - (leftNum * powers[size]) % mod + mod) % mod, sum = prefixSum[right + 1] - prefixSum[left];            

            ans[i] = (x * sum) % mod;
        }

        return ans;
    }
};

int main() {
    return 0;
}