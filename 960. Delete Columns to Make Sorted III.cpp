#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size(), m = strs.size();
        vector<int> memo(n, 1);
        for (int i = 0; i < n; i++) {
            int best = 0;
            for (int j = 0; j < i; j++) {
                bool isValidCol = true;
                for (int k = 0; k < m; k++) {
                    if (strs[k][j] > strs[k][i]) {
                        isValidCol = false;
                        break;
                    }
                }
                if (isValidCol)
                    memo[i] = max(memo[i], memo[j] + 1);
            }
        }
        return n - *max_element(memo.begin(), memo.end());
    }
};

int main() {
    return 0;
}