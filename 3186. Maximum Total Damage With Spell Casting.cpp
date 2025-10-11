#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    unordered_map<int, int> count;
    vector<int> newPower;
    vector<long long> memo;

    long long DP(int ind = 0) {
        if (ind >= n)
            return 0;
        if (memo[ind] != -1)
            return memo[ind];
        
        long long take = (long long)newPower[ind] * (long long)count[newPower[ind]] + 
        DP(lower_bound(newPower.begin(), newPower.end(), newPower[ind] + 3) - newPower.begin());
        long long noTake = DP(ind + 1);

        return memo[ind] = max(take, noTake);
    }

public:
    long long maximumTotalDamage(vector<int>& power) {                
        for (int val : power) 
            count[val]++;     
                
        for (auto [key, val] : count)
            newPower.push_back(key);
        sort(newPower.begin(), newPower.end());

        n = newPower.size();
        memo.assign(n, -1);
        return DP();
    }
};

int main() {
    return 0;
}