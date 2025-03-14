#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        bool IsPossible(vector<int>& candies, long long k, int curr) {
            for (int pile : candies)
                k -= pile / curr;   
            return k  <= 0;         
        }

    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int left = 0, right = *max_element(candies.begin(), candies.end());
            while (left < right) {
                int mid = (left + right + 1) / 2;
                if (IsPossible(candies, k, mid))
                    left = mid;
                else
                    right = mid - 1;
            }
            return left;
        }
    };

int main() {
    return 0;
}