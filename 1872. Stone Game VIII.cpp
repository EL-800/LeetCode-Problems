#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size(), best;

        vector<int> sums(n + 1);
        sums[0] = stones[0];        
        for (int i = 1; i < n; i++) 
            sums[i] = stones[i] + sums[i - 1];

        best = sums[n - 1];
        for (int i = n - 2; i >= 1; i--) 
            best = max(sums[i] - best, best);        
        return best;
    }
};

int main() {
    return 0;
}