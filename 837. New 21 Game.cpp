#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, k, maxPts; 
    double stepProb;
    vector<double> memo;

    double DP(int curr = 0) {
        if (curr >= k)
            return double(curr <= n);
        if (memo[curr] >= 0)
            return memo[curr];
        if (curr == k - 1) {            
            int i = 1;
            for (; i <= maxPts; i++) {
                if (curr + i > n)
                    break;
            }
            return memo[curr] = double(i - 1) * stepProb;
        }        
        double next = DP(curr + 1), last = DP(curr + maxPts + 1);
        return memo[curr] = next + (next - last) * stepProb;
    }

public:
    double new21Game(int n, int k, int maxPts) {
        this->n = n;
        this->k = k;
        this->maxPts = maxPts;

        stepProb = 1 / (double)maxPts;

        memo.assign(k, -1);
        return DP();
    }
};

int main() {
    return 0;
}