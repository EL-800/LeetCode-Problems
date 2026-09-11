#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;
        vector<int> count(10);

        for (int d : digits) 
            count[d]++;

        for (int i = 0; i <= 8; i += 2) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 1; k <= 9; k++) 
                    ans += count[i] > 0 && count[j] > (i == j) && count[k] > (i == k) + (j == k);                
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}