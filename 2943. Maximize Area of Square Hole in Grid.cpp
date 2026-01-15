#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int GetMaxConsecutives(vector<int>& bars) {
        int n = bars.size(), count = 1, best = 1;
        for (int i = 1; i < n; i++) {
            if (bars[i] != bars[i - 1] + 1) {
                count = 1;
                continue;
            }            
            count++;
            best = max(best, count);    
                                
        }

        return best;
    }

public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {        
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int bestH = GetMaxConsecutives(hBars);
        int bestV = GetMaxConsecutives(vBars);
        int side = min(bestV + 1, bestH + 1);        
        return side * side;
    }
};

int main() {
    return 0;
}