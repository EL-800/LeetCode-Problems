#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        int negSum = 0;
        vector<int> ans(n);
        for (int i = 1; i <= n - 1; i++) {
            ans[i - 1] = i;  
            negSum -= i;
        }
        ans[n - 1] = negSum;
        return ans; 
    }
};

int main() {
    return 0;
}