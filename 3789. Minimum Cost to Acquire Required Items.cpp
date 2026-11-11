#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int lessNeeded = min(need1, need2);
        long long both = lessNeeded * 1ll * min(costBoth, cost1 + cost2) * 1ll;
        long long remaining1 = (need1 - lessNeeded) * 1ll * min(costBoth, cost1) * 1ll;
        long long remaining2 = (need2 - lessNeeded) * 1ll * min(costBoth, cost2) * 1ll;

        return both + remaining1 + remaining2;
    }
};

int main() {
    return 0;
}