#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {            
            vector<bool> marked(right + 1);
            vector<int> primes;
            for (int i = 2; i <= right; i++) {
                if (marked[i])
                    continue;
                if (i >= left)
                    primes.push_back(i);                
                for (int j = i; j <= right; j += i) 
                    marked[j] = true;                
            }
            vector<int> ans {-1, -1};
            int diff = INT_MAX;
            for (int i = 1; i < primes.size(); i++) {
                if (primes[i] - primes[i - 1] < diff) {
                    diff = primes[i] - primes[i - 1];
                    ans = {primes[i - 1], primes[i]};
                }                
            }
            return ans;
        }
    };

int main() {
    return 0;
}