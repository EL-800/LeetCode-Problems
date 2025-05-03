#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int n = tops.size();
            vector<int> countVals(7);
            for (int i = 0; i < n; i++) {
                countVals[tops[i]]++;
                if (tops[i] != bottoms[i])
                    countVals[bottoms[i]]++;
            }
            int val = find(countVals.begin(), countVals.end(), n) - countVals.begin();
            if (val == countVals.size())
                return -1;            
            return n - max(count(tops.begin(), tops.end(), val), count(bottoms.begin(), bottoms.end(), val));
        }
    };

int main() {
    return 0;
}