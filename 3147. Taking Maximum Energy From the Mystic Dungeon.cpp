#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        const int inf = 1e9;

        int n = energy.size();
        vector<int> memo(n, inf);

        for (int i = n - 1; i >= 0; i--) {
            int curr = 0;
            for (int j = i; j >= 0; j -= k) {
                if (memo[j] != inf)
                    break;
                curr += energy[j];
                memo[j] = curr;
            }
        }

        return *max_element(memo.begin(), memo.end());
    }
};

int main() {
    return 0;
}