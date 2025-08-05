#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), m = baskets.size(), ans = n;
        vector<bool> used(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (fruits[i] <= baskets[j] && !used[j]) {
                    ans--;
                    used[j] = true;
                    break;
                }                    
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}