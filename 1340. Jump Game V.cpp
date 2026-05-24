#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, d;
    vector<int> memo;

    int dp(vector<int>& arr, int ind) {        
        if (memo[ind] != -1)
            return memo[ind];
        
        int bestJump = 0;
        for (int i = ind + 1; i <= ind + d; i++) {
            if (i >= n)
                break;
            if (arr[ind] <= arr[i])
                break;
            bestJump = max(bestJump, dp(arr, i));
        }

        for (int i = ind - 1; i >= ind - d; i--) {
            if (i < 0)
                break;
            if (arr[ind] <= arr[i])
                break;
            bestJump = max(bestJump, dp(arr, i));
        }

        return memo[ind] = bestJump + 1;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        this->d = d;
        memo.assign(n, -1);
        int ans = 0;

        for (int i = 0; i < n; i++) 
            ans = max(ans, dp(arr, i));        
        
        return ans;
    }
};

int main() {
    return 0;
}