#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const long long mod = 1e9 + 7;

        vector<long long> usedBits;
        long long currPower = 1;
        while (currPower <= n) {
            if (n & currPower)
                usedBits.push_back(currPower);
            currPower <<= 1;
        }

        vector<int> ans(queries.size(), 1);
        for (int i = 0; i < queries.size(); i++) {            
            for (int j = queries[i][0]; j <= queries[i][1]; j++) 
                ans[i] = ((long long)ans[i] * usedBits[j]) % mod;
        }
        return ans;
    }
};

int main() {
    return 0;
}