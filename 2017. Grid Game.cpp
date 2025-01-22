#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m = grid[0].size();
        long long sum1 = accumulate(grid[0].begin(), grid[0].end(), 0LL), sum2 = 0, ans = LLONG_MAX;        
        for (int i = 0; i < m; i++) {
            sum1 -= grid[0][i];
            ans = min(ans, max(sum1, sum2));
            sum2 += grid[1][i];
        }
        return ans;
    }
};

int main() {
    return 0;
}