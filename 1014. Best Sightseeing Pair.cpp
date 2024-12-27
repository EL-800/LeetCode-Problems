#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int bestPrev = 1, ans = 0;
        for (int value : values) {
            bestPrev--;
            ans = max(bestPrev + value, ans);
            bestPrev = max(bestPrev, value);                        
        }
        return ans;
    }
};

int main() {
    return 0;
}