#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitsCount(24);
        for (int candidate : candidates) {
            int ind = 0;
            while (candidate) {
                bitsCount[ind] += candidate & 1;
                candidate >>= 1;
                ind++;
            }
        }
        return *max_element(bitsCount.begin(), bitsCount.end());
    }
};

int main() {
    return 0;
}