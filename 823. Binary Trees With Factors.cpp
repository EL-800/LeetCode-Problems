#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution {
private:
    const int mod = (int) 1e9 + 7;
    long long CountComb(unordered_set<int>& uniques, unordered_map<int, long long>& dp, int curr){
        if (dp.count(curr))
            return dp[curr];   
        dp[curr] = 1;
        for (int uni : uniques){
            if (curr % uni == 0 && uniques.count(curr / uni))
                dp[curr] = (dp[curr] + (CountComb(uniques, dp, uni) * CountComb(uniques, dp, curr / uni)) % mod) % mod;                
        }
        return dp[curr] % mod;
    }

public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long long> dp;
        unordered_set<int> uniques(arr.begin(), arr.end());
        int ans = 0;
        for(int curr : uniques)
            ans = (ans + CountComb(uniques, dp, curr)) % mod;        
        return ans % mod;
    }
};

int main(){
    vector<int> a = {2, 4};
    Solution b;    
    cout << b.numFactoredBinaryTrees(a);
    return 0;
}