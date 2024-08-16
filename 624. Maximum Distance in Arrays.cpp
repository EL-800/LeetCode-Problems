#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minE = *arrays.begin()->begin(), maxE = *arrays.begin()->rbegin(), ans = 0;
        for(int i = 1; i < arrays.size(); i++) {
            int localMin = *arrays[i].begin(), localMax = *arrays[i].rbegin();
            ans = max(ans, max(localMax - minE, maxE - localMin));
            minE = min(minE, localMin);
            maxE = max(maxE, localMax);
        }
        return ans;
    }
};

int main() {
    return 0;
}