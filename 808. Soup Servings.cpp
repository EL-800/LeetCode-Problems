#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<int, unordered_map<int, double>> dp;

    double CalculateProb(int a, int b) {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (a <= 0)
            return 1;
        if (b <= 0)
            return 0;
        if (dp.count(a) && dp[a].count(b))
            return dp[a][b];
        return dp[a][b] = 0.25 * (CalculateProb(a - 100, b) + CalculateProb(a - 75, b - 25) + CalculateProb(a - 50, b - 50) + CalculateProb(a - 25, b - 75));
    }
public:
    double soupServings(int n) {   
        for (int i = 1; i <= n; i += 25) {
            if (CalculateProb(i, i) > 1 - (1e-5))
                return 1;
        }
        return CalculateProb(n, n);
    }
};

int main() {
    return 0;
}