#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int furthestInd = n - 1, furthestColor = colors[n - 1], secondFurthestInd = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (colors[i] != furthestColor) {
                secondFurthestInd = i;
                break;                
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (colors[i] == furthestColor) 
                ans = max(ans, secondFurthestInd - i);
            else
                ans = max(ans, furthestInd - i);
        }

        return ans;
    }
};

int main() {
    return 0;
}