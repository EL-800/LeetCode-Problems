#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for (int i = 0; i < min(limit, n); i++) 
            ans += max((long long)min(limit, n - i) - (long long)max(0, n - i - limit) + 1ll, 0ll);
        return ans;
    }
};

int main() {
    return 0;
}