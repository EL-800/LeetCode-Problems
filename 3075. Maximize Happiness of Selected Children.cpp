#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());

        long long ans = 0ll;        
        for (int i = 0; i < k; i++) 
            ans += max((long long)(happiness[i] - i), 0ll);                                            

        return ans;
    }
};

int main() {
    return 0;
}