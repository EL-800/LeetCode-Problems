#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int low, high, zero, one, mod = 1e9 +7;
    vector<int> memo;

    int DP(int currInd = 0) {
        if (currInd > high)
            return 0;
        if (memo[currInd] != -1)
            return memo[currInd];
        long long currAns = (DP(currInd + zero) + DP(currInd + one) + (currInd >= low)) % mod;
        return memo[currInd] = currAns;        
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        this->zero = zero, this->one = one, this->low = low, this->high = high;
        memo.assign(high + 1, -1);
        return DP() % mod;
    }
};

int main() {
    Solution s;
    cout << s.countGoodStrings(3, 3, 1, 1);
    return 0;
}