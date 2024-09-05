#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int missingSum = (n + rolls.size()) * mean - accumulate(rolls.begin(), rolls.end(), 0);                
        vector<int> ans(n, 1);    
        if (n > missingSum)
            return vector<int>();    
        for (int i = 1; i <= 6; i++) {
            for (int j = 0; j < n; j++) {
                ans[j] = i;
                missingSum--;                                
                if (!missingSum)
                    return ans;
            }            
        }
        return vector<int>();
    }
};

int main() {
    return 0;
}