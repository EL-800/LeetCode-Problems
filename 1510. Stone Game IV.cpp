#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> memo;

    bool dp(int n) {
        if (!n)
            return 0;
        if (memo[n] != -1)
            return memo[n];

        for (int i = 1; i * i <= n; i++) {
            if (!dp(n - i * i))
                return memo[n] = 1;
        }

        return memo[n] = 0;
    }

public:
    bool winnerSquareGame(int n) {
        memo.assign(n + 1, -1);
        return (bool)dp(n);
    }
};

int main() {
    return 0;
}