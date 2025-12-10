#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int mod = 1e9 + 7;
        int lowest = *min_element(complexity.begin() + 1, complexity.end());

        if (complexity[0] >= lowest)
            return 0;
        
        int n = complexity.size();
        long long ans = 1;
        for (long long i = 1; i <= n - 1; i++) 
            ans = (ans * i) % mod;        
        return (int)ans;
    }
};

int main() {
    return 0;
}